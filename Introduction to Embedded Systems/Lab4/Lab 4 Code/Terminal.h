#ifndef TERMINAL_H_
#define TERMINAL_H_

#include "DataLog.h"

typedef struct terminalTaskData {
    bool* resetFlag;
    float* tempMin;
    float* tempMax;
    float* currMin;
    float* currMax;
    float* voltMin;
    float* voltMax;
} terminalData;


void terminalTask (void*);

#endif
