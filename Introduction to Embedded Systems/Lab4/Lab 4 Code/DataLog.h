#ifndef DATALOG_H_
#define DATALOG_H_

#include <stdbool.h>
#include "Arduino.h"
#include "EEPROM.h"

typedef struct dataLogTaskData {
    bool* resetFlag;
    const int* tempMinAddr;
    const int* tempMaxAddr;
    const int* currMinAddr;
    const int* currMaxAddr;
    const int* voltMinAddr;
    const int* voltMaxAddr;
    bool* tempMinChanged;
    bool* tempMaxChanged;
    bool* currMinChanged;
    bool* currMaxChanged;
    bool* voltMinChanged;
    bool* voltMaxChanged;
    float* tempMin;
    float* tempMax;
    float* currMin;
    float* currMax;
    float* voltMin;
    float* voltMax;
} dataLogData;


void dataLogTask (void*);

void writeToEEPROM(float* value, int valueAddr);

void resetMeasurementHistory(dataLogData* data);

float readFromEEPROM(int valueAddr);

#endif
