#include <stdbool.h>
#include <Elegoo_GFX.h>
#include <Elegoo_TFTLCD.h>
#include <TouchScreen.h>

#include "TaskControlBlock.h"
#include "Scheduler.h"
#include "Measurement.h"
#include "SOC.h"
#include "Alarm.h"
#include "Contactor.h"
#include "Display.h"
#include "TouchInput.h"

#define LCD_CS A3     // Chip Select goes to Analog 3
#define LCD_CD A2     // Command/Data goes to Analog 2
#define LCD_WR A1     // LCD Write goes to Analog 1
#define LCD_RD A0     // LCD Read goes to Analog 0
#define LCD_RESET A4  // Can alternately just connect to Arduino's reset pin

#define MAX_LEN 32

// Setup the TFT with the correct pins
Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

#define YP A3  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 9   // can be a digital pin
#define XP 8   // can be a digital pin

// Setup the touchscreen with the correct pins
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

// Time since we started looping
int secondsElapsed;

//Task Control Blocks
TCB measurementTCB;
TCB socTCB;
TCB contactorTCB;
TCB alarmTCB;
TCB touchInputTCB;
TCB displayTCB;

// TCB Queue
#define QUEUE_SIZE 6
TCB* TCBQueue[QUEUE_SIZE] = {&measurementTCB, &socTCB, &contactorTCB, &alarmTCB, &displayTCB, &touchInputTCB};

// Measurement Data
measurementData measure;                      // Declare measurement data structure - defined in Measurement.h
float hvCurrent     = 0;                      // The system's HV Current value
float hvVoltage     = 0;                      // The system's HV Voltage value
float temperature   = 0;                      // The system's Temperature value
bool hvil           = 0;                      // The system's HVIL status
bool hvilChanged    = true;                   // Whether or not the HVIL's status has changed
const byte hvilPin  = 47;                     // The pin the system is reading to see the HVIL's status

// SOC Data
socData soc;                                  // Declare SOC data structure - defined in SOC.h
float charge = 0;                             // The system's state of charge

// Contactor Data
contactorData contactor;                      // Declare contactor data structure - defined in Contactor.h
int contactorFlag       = 1;                  // A flag to tell the system whether or not to change the contactor's status and what to change it to
const byte contactorPin = 39;                 // The pin the system is writing to to show the contactor's status
bool contactorStatus    = CONTACTOR_OPEN;     // The contactor's current status. Initially starts as open

// Alarm Data
alarmData alarm;                              // Declare alarm data structure - defined in Alarm.h
char* hvilAlarmStatus     = "";               // The system's HVIL alarm status
char* overcurrentStatus   = "";               // The system's Overcurrent alarm status
char* hvOutOfRangeStatus  = "";               // The system's HVOOR alarm status

// Display Data
displayData displayD;                         // Declare display data structure - defined in Display.h
int page    = MEASURE_PAGE;                   // The current page the system is displaying. Start at the measurement page
int oldPage = -1;                             // The page the system was displaying in the previous cycle. Start at a non-page value

// Touch Input Data
touchInputData touchInput;                    // Declare touch input data structure - defined in TouchInput.h

void setup() {
  Serial.begin(9600);
  Serial.println(F("TFT LCD test"));


#ifdef USE_Elegoo_SHIELD_PINOUT       // This is defined in Elegoo_TFTLCD.h
  Serial.println(F("Using Elegoo 2.4\" TFT Arduino Shield Pinout"));
#else
  Serial.println(F("Using Elegoo 2.4\" TFT Breakout Board Pinout"));
#endif

  Serial.print("TFT size is "); Serial.print(tft.width()); Serial.print("x"); Serial.println(tft.height());

  tft.reset();

  uint16_t identifier = tft.readID();
  if (identifier == 0x9325) {
    Serial.println(F("Found ILI9325 LCD driver"));
  } else if (identifier == 0x9328) {
    Serial.println(F("Found ILI9328 LCD driver"));
  } else if (identifier == 0x4535) {
    Serial.println(F("Found LGDP4535 LCD driver"));
  } else if (identifier == 0x7575) {
    Serial.println(F("Found HX8347G LCD driver"));
  } else if (identifier == 0x9341) {
    Serial.println(F("Found ILI9341 LCD driver"));
  } else if (identifier == 0x8357) {
    Serial.println(F("Found HX8357D LCD driver"));
  } else if (identifier == 0x0101)
  {
    identifier = 0x9341;
    Serial.println(F("Found 0x9341 LCD driver"));
  }
  else if (identifier == 0x1111)
  {
    identifier = 0x9328;
    Serial.println(F("Found 0x9328 LCD driver"));
  }
  else {
    Serial.print(F("Unknown LCD driver chip: "));
    Serial.println(identifier, HEX);
    Serial.println(F("If using the Elegoo 2.8\" TFT Arduino shield, the line:"));
    Serial.println(F("  #define USE_Elegoo_SHIELD_PINOUT"));
    Serial.println(F("should appear in the library header (Elegoo_TFT.h)."));
    Serial.println(F("If using the breakout board, it should NOT be #defined!"));
    Serial.println(F("Also if using the breakout, double-check that all wiring"));
    Serial.println(F("matches the tutorial."));
    identifier = 0x9328;

  }
  tft.begin(identifier);
  tft.setRotation(2);

  // Initialize the seconds elapsed since the system began
  secondsElapsed = 0;

  // Initilize the measurement data structure with the correct values
  measure                     = {&hvil, &hvilChanged, &hvilPin, &temperature, &hvCurrent, &hvVoltage, &secondsElapsed};
  measurementTCB.task         = &measurementTask;
  measurementTCB.taskDataPtr  = &measure;
  measurementTCB.next         = NULL;
  measurementTCB.prev         = NULL;

  // Initilize the SOC data structure with the correct values
  soc                         = {&charge, &secondsElapsed};
  socTCB.task                 = &socTask;
  socTCB.taskDataPtr          = &soc;
  socTCB.next                 = NULL;
  socTCB.prev                 = NULL;

  // Initilize the contactor data structure with the correct values
  contactor                   = {&contactorStatus, &contactorFlag, &contactorPin};
  contactorTCB.task           = &contactorTask;
  contactorTCB.taskDataPtr    = &contactor;
  contactorTCB.next           = NULL;
  contactorTCB.prev           = NULL;

  // Initilize the alarm data structure with the correct values
  alarm                       = {&hvilAlarmStatus, &overcurrentStatus, &hvOutOfRangeStatus, &secondsElapsed};
  alarmTCB.task               = &alarmTask;
  alarmTCB.taskDataPtr        = &alarm;
  alarmTCB.next               = NULL;
  alarmTCB.prev               = NULL;

  // Initilize the display data structure with the correct values
  displayD                    = {&measure, &soc, &alarm, &contactor, &page, &oldPage, &tft, &secondsElapsed};
  displayTCB.task             = &displayTask;
  displayTCB.taskDataPtr      = &displayD;
  displayTCB.next             = NULL;
  displayTCB.prev             = NULL;

  // Initilize the touch input data structure with the correct values
  touchInput                  = {&ts, &contactorFlag, &page, &oldPage, &secondsElapsed};
  touchInputTCB.task          = &touchInputTask;
  touchInputTCB.taskDataPtr   = &touchInput;
  touchInputTCB.next          = NULL;
  touchInputTCB.prev          = NULL;

  // Set the input and output pins to their correct modes
  pinMode(contactorPin, OUTPUT);
  pinMode(hvilPin, INPUT);
  
}

void loop() {
  // Sets the positive-y and minus-x pins to output so that the TFT display can update values
  pinMode(YP, OUTPUT);
  pinMode(XM, OUTPUT);
  // Let the scheduler run the TCBs in the TCB queue
  scheduler(TCBQueue, QUEUE_SIZE);
  // Increment the number of seconds since the system started running
  secondsElapsed++;
}
