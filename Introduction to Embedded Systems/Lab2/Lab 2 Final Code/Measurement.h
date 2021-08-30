#ifdef __cplusplus  
extern "C" { 
#endif 

#ifndef MEASUREMENT_H_
#define MEASUREMENT_H_


#define HVIL_OPEN   false       // Value that tells us that the HVIL is open
#define HVIL_CLOSED true        // Value that tells us that the HVIL is closed

#include <stdbool.h>
#include <Arduino.h>


typedef struct measurementTaskData {
    bool* hvilStatus;
    bool* hvilChanged;
    const byte* hvilPin;
    float* temperature;
  	float* hvCurrent;
  	float* hvVoltage;
  	int* seconds;
} measurementData;


void measurementTask (void*);


#endif

#ifdef __cplusplus 
} 
#endif 
