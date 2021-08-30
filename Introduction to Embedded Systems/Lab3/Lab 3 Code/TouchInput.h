#ifndef TOUCH_INPUT_H_
#define TOUCH_INPUT_H_

#include <Elegoo_GFX.h>
#include <Elegoo_TFTLCD.h>
#include <Touchscreen.h>
#include <stdbool.h>
#include "Display.h"
#include "Contactor.h"
#include "Alarm.h"
#include "Arduino.h"

#define TS_MIN_X 930    // The touchscreen's minimum x-value
#define TS_MAX_X 90     // The touchscreen's maximum x-value
#define TS_MIN_Y 70     // The touchscreen's minimum y-value
#define TS_MAX_Y 920    // The touchscreen's maximum y-value
#define YP 8            // The positive-y pin for the touchscreen
#define XM 9            // The minus-x pin for the touchscreen

typedef struct inputTaskData {
    TouchScreen* ts;
    int* contactorFlag;
    int* page;
    bool* hvilAcknowledged;
    bool* ocAcknowledged;
    bool* hvoorAcknowledged;
    volatile int* hvilStatus;
    int* overcurrentStatus;
    int* hvoorStatus;
} touchInputData;

void touchInputTask (void*);

#endif
