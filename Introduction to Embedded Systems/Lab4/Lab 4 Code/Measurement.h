#ifndef MEASUREMENT_H_
#define MEASUREMENT_H_


#define HVIL_OPEN   1       // Value that tells us that the HVIL is open
#define HVIL_CLOSED 0       // Value that tells us that the HVIL is closed

#include <stdbool.h>
#include <Arduino.h>
#include "Alarm.h"
#include "DataLog.h"

typedef struct measurementTaskData {
    bool* hvilStatus;
    bool* hvilChanged;
    const byte* hvilPin;
    float* temperature;
    bool* tempChanged;
    const byte* tempPin;
  	float* hvCurrent;
  	bool* currChanged;
    const byte* currPin;
  	float* hvVoltage;
  	bool* voltChanged;
    const byte* voltPin;
    dataLogData* dlData;
} measurementData;


void measurementTask (void*);

#endif