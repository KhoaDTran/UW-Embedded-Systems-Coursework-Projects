#include "TouchInput.h"
#include <Touchscreen.h>
#include "Measurement.h"

void alarmInput(TouchScreen ts, TSPoint p, int hvilStatus, bool* hvilAcknowledged, int overcurrentStatus,
                bool* ocAcknowledged, int hvoorStatus, bool* hvoorAcknowledged) {
    /****************
    * Function name: alarmInput
    * Function inputs: the touchscreen, the point we touched at, the HVIL status, the HVIL acknowledgement status,
    * the overcurrent status, the overcurrent acknowledgement status, the HVOOR status, and the HVOOR acknowledgement status,
    * Function outputs: none
    * Function description: Flags the system to say what alarms need to be marked as acknowledged
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    // Only change the acknowledgements if our input was past the touchscreen's pressure threshhold
    if (p.z > ts.pressureThreshhold) {
        // If you press the acknowledge button, acknowledge the unacknowledged alarms
        if (p.x >= 26 && p.x <= 214 && p.y >= 172 && p.y <= 217) {
            // Acknowledge the HVIL alarm if it's active and not acknowledged
            if (hvilStatus == ANA) {
                *hvilAcknowledged = true;
            }
            // Acknowledge the overcurrent alarm if it's active and not acknowledged
            if (overcurrentStatus == ANA) {
                *ocAcknowledged = true;
            }
            // Acknowledge the HVOOR alarm if it's active and not acknowledged
            if (hvoorStatus == ANA) {
                *hvoorAcknowledged = true;
            }
        }
    }
}

void batteryInput(TouchScreen ts, TSPoint p, int* contactorFlag) {
    /****************
    * Function name: batteryInput
    * Function inputs: the touchscreen, the point we touched at, and a pointer to the system's contactor flag
    * Function outputs: none
    * Function description: Flags the system to say if the contactor's status needs to be changed and to what
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    // Only change the battery status if our input was past the touchscreen's pressure threshhold
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
}

void pageChange(TouchScreen ts, TSPoint p, int* page) {
    /****************
    * Function name: pageChange
    * Function inputs: the touchscreen, the point we touched at, and a pointer to the system's page
    * Function outputs: none
    * Function description: Updates which page the user wants to be on
    * Author(s): Yasin Alissa, Khoa Tran
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
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    // Disable interrupts as this function uses some data changed in the HVIL interrupt task
    noInterrupts();

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

    // Update the alarm acknowledgements based on input
    if (*data->page == ALARM_PAGE) {
        alarmInput(ts, p, *data->hvilAlarmStatus, data->hvilAcknowledged, *data->overcurrentAlarmStatus, data->ocAcknowledged,
                   *data->hvoorAlarmStatus, data->hvoorAcknowledged);
    }

    // Update the battery and contactor's status based on input
    if (*data->page == BATTERY_PAGE) {
        batteryInput(ts, p, data->contactorFlag);
    }

    // If there are alarms to acknowledge, keep the user on the alarm page. Else, update the page based on input
    bool alarmsToAcknowledge = (*data->hvilAlarmStatus == ANA && *data->hvilStatus == HVIL_CLOSED) ||
            *data->overcurrentAlarmStatus == ANA || *data->hvoorAlarmStatus == ANA;
    if (alarmsToAcknowledge) {
        *data->page = ALARM_PAGE;
    } else {
        pageChange(ts, p, data->page);
    }

    // Enable interrupts again
    interrupts();
}