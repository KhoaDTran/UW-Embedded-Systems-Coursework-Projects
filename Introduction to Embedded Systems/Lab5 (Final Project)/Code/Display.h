#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <stdbool.h>
#include "Arduino.h"
#include "Measurement.h"
#include "SOC.h"
#include "Alarm.h"
#include "Contactor.h"
#include "Accelerometer.h"
#include <Elegoo_GFX.h>
#include <Elegoo_TFTLCD.h>

#define STARTUP -1              // Value to signify the system just started up
#define MEASURE_PAGE 0          // Value to signify the measurement page of our system
#define ALARM_PAGE 1            // Value to signify the alarms page of our system
#define BATTERY_PAGE 2          // Value to signify the battery on/off page of our system
#define ACCELEROMETER_PAGE 3    // Value to signify the accelerometer page of our system

typedef struct displayTaskData {
    measurementData* mData;
    socData* sData;
    alarmData* aData;
    contactorData* cData;
    accelerometerData* acData;
    int* currPage;
    int* oldPage;
    Elegoo_TFTLCD* tft;
    bool* alarmButtonDrawn;
    bool* socChanged;
} displayData;

void displayTask (void*);

#endif
