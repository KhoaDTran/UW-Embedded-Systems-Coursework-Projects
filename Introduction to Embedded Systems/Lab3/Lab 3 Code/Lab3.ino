#include <TimerOne.h>
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

// Have a time base flag for our interrupt sequence. Volatile becuase it's modified in the timer ISR
volatile bool timeBaseFlag;

//Task Control Blocks
TCB measurementTCB;
TCB socTCB;
TCB contactorTCB;
TCB alarmTCB;
TCB touchInputTCB;
TCB displayTCB;

// TCB LinkedList
TCB* TCBLL = &measurementTCB;

// Measurement Data
measurementData measure;                      // Declare measurement data structure - defined in Measurement.h
float hvCurrent     = 0;                      // The system's HV Current value
bool currChanged    = true;                   // Whether or not the current has changed
const byte currPin  = A11;                    // The pin the system is reading to see the current
float hvVoltage     = 0;                      // The system's HV Voltage value
bool voltChanged    = true;                   // Whether or not the voltage has changed
const byte voltPin  = A12;                    // The pin the system is reading to see the voltage
float temperature   = 0;                      // The system's Temperature value
bool tempChanged    = true;                   // Whether or not the temperature has changed
const byte tempPin  = A10;                    // The pin the system is reading to see the temperature
bool hvilChanged    = true;                   // Whether or not the HVIL's status has changed
const byte hvilPin  = 19;                     // The pin the system is reading to see the HVIL's status
bool hvil           = digitalRead(hvilPin);   // The system's HVIL status

// SOC Data
socData soc;                                  // Declare SOC data structure - defined in SOC.h
float charge = 0;                             // The system's state of charge

// Contactor Data
contactorData contactor;                      // Declare contactor data structure - defined in Contactor.h
int contactorFlag       = UNCHANGED_CONT;     // A flag to tell the system whether or not to change the contactor's status and what to change it to
const byte contactorPin = 51;                 // The pin the system is writing to to show the contactor's status
bool contactorStatus    = CONTACTOR_OPEN;     // The contactor's current status. Initially starts as open

// Alarm Data
alarmData alarm;                              // Declare alarm data structure - defined in Alarm.h
bool hvilAcknowledged           = false;      // Whether or not the HVIL alarm has been acknowledged
volatile int hvilAlarmStatus    = NA;         // The system's HVIL alarm status. Volatile because it's modified in the HVIL ISR
volatile bool hvilAlarmChanged  = true;       // Whether or not the HVIL alarm has changed
bool ocAcknowledged             = false;      // Whether or not the overcurrent alarm has been acknowledged
int overcurrentStatus           = NA;         // The system's overcurrent alarm status
bool overcurrentChanged         = true;       // Whether or not the overcurrent alarm has changed
bool hvoorAcknowledged          = false;      // Whether or not the HVOOR alarm has been acknowledged
int hvoorStatus                 = NA;         // The system's HVOOR alarm status
bool hvoorChanged               = true;       // Whether or not the HVOOR alarm has changed
volatile bool ISRFlag           = false;      // Flag to tell is if the HVIL ISR function just ran

// Display Data
displayData displayD;                         // Declare display data structure - defined in Display.h
int page              = MEASURE_PAGE;         // The current page the system is displaying. Start at the measurement page
int oldPage           = -1;                   // The page the system was displaying in the previous cycle
bool alarmButtonDrawn = false;                // Whether or not the alarm acknowledgement button is drawn

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

  // Set up the touch screen display
  tft.begin(identifier);
  tft.setRotation(2);

  // Initilize the measurement data structure with the correct values
  measure                     = {&hvil, &hvilChanged, &hvilPin, &temperature, &tempChanged, &tempPin, &hvCurrent, &currChanged, &currPin, &hvVoltage, &voltChanged, &voltPin};
  measurementTCB.task         = &measurementTask;
  measurementTCB.taskDataPtr  = &measure;
  measurementTCB.next         = &socTCB;
  measurementTCB.prev         = NULL;

  // Initilize the SOC data structure with the correct values
  soc                         = {&charge};
  socTCB.task                 = &socTask;
  socTCB.taskDataPtr          = &soc;
  socTCB.next                 = &contactorTCB;
  socTCB.prev                 = &measurementTCB;

  // Initilize the contactor data structure with the correct values
  contactor                   = {&contactorStatus, &contactorFlag, &contactorPin, &hvilAlarmStatus};
  contactorTCB.task           = &contactorTask;
  contactorTCB.taskDataPtr    = &contactor;
  contactorTCB.next           = &alarmTCB;
  contactorTCB.prev           = &socTCB;

  // Initilize the alarm data structure with the correct values
  alarm                       = {&hvilAcknowledged, &hvilAlarmStatus, &hvilAlarmChanged, &hvil, &ocAcknowledged, &overcurrentStatus, &overcurrentChanged,
                                 &hvCurrent, &hvoorAcknowledged, &hvoorStatus, &hvoorChanged, &hvVoltage, &ISRFlag};
  alarmTCB.task               = &alarmTask;
  alarmTCB.taskDataPtr        = &alarm;
  alarmTCB.next               = &displayTCB;
  alarmTCB.prev               = &contactorTCB;

  // Initilize the display data structure with the correct values
  displayD                    = {&measure, &soc, &alarm, &contactor, &page, &oldPage, &tft, &alarmButtonDrawn};
  displayTCB.task             = &displayTask;
  displayTCB.taskDataPtr      = &displayD;
  displayTCB.next             = &touchInputTCB;
  displayTCB.prev             = &alarmTCB;

  // Initilize the touch input data structure with the correct values
  touchInput                  = {&ts, &contactorFlag, &page, &hvilAcknowledged, &ocAcknowledged, &hvoorAcknowledged, &hvilAlarmStatus, &overcurrentStatus, &hvoorStatus};
  touchInputTCB.task          = &touchInputTask;
  touchInputTCB.taskDataPtr   = &touchInput;
  touchInputTCB.next          = NULL;
  touchInputTCB.prev          = &displayTCB;

  // Set the input and output pins to their correct modes
  pinMode(contactorPin, OUTPUT);
  pinMode(hvilPin, INPUT);
  pinMode(tempPin, INPUT_PULLUP);
  pinMode(currPin, INPUT_PULLUP);
  pinMode(voltPin, INPUT_PULLUP);

  // Initialize the timer to run at 10 Hz
  Timer1.initialize(100000);
  Timer1.attachInterrupt(timerISR);
  Timer1.start();
  timeBaseFlag = true;

  // Set up the HVIL interrupt routine
  attachInterrupt(digitalPinToInterrupt(hvilPin), hvilISR, RISING);

  // Make the HVIL input pin available for GPIO; generally, it's used for Serial1
  Serial1.end();

}

void loop() {
  // Let the scheduler run the TCBs in the TCB linked list only when the hardware timer allows it
  if (timeBaseFlag == true) {
    // Sets the positive-y and minus-x pins to output so that the TFT display can update values
    pinMode(YP, OUTPUT);
    pinMode(XM, OUTPUT);

    // Reset the timer flag to that the tasks only run at the correct time
    timeBaseFlag = false;

    // Let the scheduler run the tasks
    scheduler(TCBLL);
  }
}

void timerISR() {
  /****************
      Function name: timerISR
      Function inputs: none
      Function outputs: none
      Function description: Performs the timer's interrupt routine
      Author(s): Yasin Alissa, Khoa Tran
    *****************/
  // Set the time base flag to true so the scheduler can run tasks
  timeBaseFlag = true;
}

void hvilISR() {
  /****************
    Function name: hvilInterrupt
    Function inputs: none
    Function outputs: none
    Function description: Performs the HVIL interrupt routine
    Author(s): Yasin Alissa, Khoa Tran
  *****************/
  // Set the HVIL alarm's status to active not acknowledged
  hvilAlarmStatus = ANA;
  hvilAlarmChanged = true;
  // Open the contactor directly
  digitalWrite(contactorPin, LOW);
  // Set the flag that signifies the HVIL ISR running
  ISRFlag = true;
}
