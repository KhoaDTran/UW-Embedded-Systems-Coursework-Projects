#include <Touchscreen.h>
#include "TouchInput.h"
#include "Contactor.h"

void batteryInput(TouchScreen ts, TSPoint p, int* contactorFlag) {
    /****************
    * Function name: batteryInput
    * Function inputs: the touchscreen, the point we touched at, and a pointer to the system's contactor flag
    * Function outputs: none
    * Function description: Flags the system to say if the contactor's status needs to be changed and to what
    * Author(s): Yasin Alissa
    *****************/
    // Only change the page if our input was past the touchscreen's pressure threshhold
    if (p.z > ts.pressureThreshhold) {
        // If you press the on button, close the contactor and exit
        if (p.x >= 26 && p.x <= 94 && p.y >= 172 && p.y <= 217) {
            *contactorFlag = CLOSE;
            return;
            // If you press the off button, open the contactor and exit
        } else if (p.x >= 146 && p.x <= 214 && p.y >= 172 && p.y <= 217) {
            *contactorFlag = OPEN;
            return;
        }
    }
    // Neither button was pressed, so keep the contactor's status the same
    *contactorFlag = UNCHANGED_CONT;
}

void pageChange(TouchScreen ts, TSPoint p, int* page) {
    /****************
    * Function name: pageChange
    * Function inputs: the touchscreen, the point we touched at, and a pointer to the system's page
    * Function outputs: none
    * Function description: Updates which page the user wants to be on
    * Author(s): Yasin Alissa
    *****************/
    // Only change the page if our input was past the touchscreen's pressure threshhold
    if (p.z > ts.pressureThreshhold) {
        // If you press the measure button, switch to the measure page
        if (p.x >= 9 && p.x <= 77 && p.y >= 255 && p.y <= 300) {
            *page = MEASURE_PAGE;
            // If you press the alarm button, switch to the alarm page
        } else if (p.x >= 86 && p.x <= 154 && p.y >= 255 && p.y <= 300) {
            *page = ALARM_PAGE;
            // If you press the battery button, switch to the battery on/off page
        } else if (p.x >= 163 && p.x <= 231 && p.y >= 255 && p.y <= 300) {
            *page = BATTERY_PAGE;
        }
    }
}

void touchInputTask(void* iData) {
    /****************
    * Function name: touchInputTask
    * Function inputs: void* pointer to the socData struct
    * Function outputs: none
    * Function description: Updates all state of charge status once per second
    * Author(s): Yasin Alissa
    *****************/
    touchInputData* data = (touchInputData*) iData;

    // Make sure the touchscreen can read input
    TouchScreen ts = *data->ts;
    pinMode(YP, INPUT);
    pinMode(XM, INPUT);

    // Get the point we're touching on the touchscreen
    TSPoint p = ts.getPoint();

    // The TFT and touchscreen share pins, so make sure the TFT is able to output now
    pinMode(YP, OUTPUT);
    pinMode(XM, OUTPUT);

    // Map the touchscreen's coordinates to the TFT's coordinates
    p.x = map(p.x, TS_MIN_X, TS_MAX_X, 0, 240);
    p.y = map(p.y, TS_MIN_Y, TS_MAX_Y, 0, 320);

    // Update the battery and contactor's status based on input
    batteryInput(ts, p, data->contactorFlag);

    // Update the page we're on based on input
    pageChange(ts, p, data->page);
}