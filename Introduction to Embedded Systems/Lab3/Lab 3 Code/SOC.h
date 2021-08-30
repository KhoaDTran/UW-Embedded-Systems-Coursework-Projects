#ifdef __cplusplus
extern "C" {
#endif

#ifndef SOC_H_
#define SOC_H_

#include <Arduino.h>

typedef struct socTaskData {
    float* charge;
} socData;


void socTask (void*);


#endif

#ifdef __cplusplus
}
#endif
