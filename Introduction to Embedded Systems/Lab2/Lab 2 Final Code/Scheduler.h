#ifdef __cplusplus
extern "C" {
#endif

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "Arduino.h"
#include "TaskControlBlock.h"

void scheduler(TCB* queue[], int size);

#endif

#ifdef __cplusplus
}
#endif
