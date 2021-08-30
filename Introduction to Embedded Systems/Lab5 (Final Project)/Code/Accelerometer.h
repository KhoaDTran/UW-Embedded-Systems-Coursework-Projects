#ifndef ACCELEROMETER_H_
#define ACCELEROMETER_H_

#include "Arduino.h"

typedef struct accelerometerTaskData {
    const byte* xPin;
    const byte* yPin;
    const byte* zPin;
    float* timeBase;
    float* currXPos;
    float* currYPos;
    float* currZPos;
    float* currXVel;
    float* currYVel;
    float* currZVel;
    float* currXAcc;
    float* currYAcc;
    float* currZAcc;
    float* totalDist;
    float* currXAng;
    float* currYAng;
    float* currZAng;
} accelerometerData;

void accelerometerTask (void*);

void calibrate(const byte xPin, const byte yPin, const byte zPin);

#endif
