#ifdef __cplusplus
extern "C" {
#endif

#ifndef CONTACTOR_H_
#define CONTACTOR_H_

#include <stdbool.h>
#include <Arduino.h>

#define CONTACTOR_OPEN true         // Value to signify that the contactor is open
#define CONTACTOR_CLOSED false      // Value ot signify that the contactor is closed
#define CLOSE -1                    // Value to tell the program to close the contactor
#define OPEN 1                      // Value to tell the program to open the contactor
#define UNCHANGED_CONT 0            // Value to tell the program to keep the contactor the same

typedef struct contactorTaskData {
    bool* contactorStatus;
    int* contactorFlag;
    const byte* contactorPin;
} contactorData;


void contactorTask (void*);


#endif

#ifdef __cplusplus
}
#endif
