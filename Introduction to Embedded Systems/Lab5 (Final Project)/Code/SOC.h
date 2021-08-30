#ifdef __cplusplus
extern "C" {
#endif

#ifndef SOC_H_
#define SOC_H_

#include <stdbool.h>

typedef struct socTaskData {
    float* charge;
    float* temperature;
    float* current;
    float* voltage;
    bool* socChanged;
} socData;


void socTask (void*);


#endif

#ifdef __cplusplus
}
#endif
