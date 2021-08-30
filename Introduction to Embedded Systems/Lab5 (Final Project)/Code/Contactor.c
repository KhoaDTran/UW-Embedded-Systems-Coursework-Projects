#include "Contactor.h"
#include "Alarm.h"

void contactorTask(void* cData) {
    /****************
    * Function name: contactorTask
    * Function inputs: void* pointer to the alarmData struct
    * Function outputs: none
    * Function description: Updates the contactor's status and turns on the contactor LED only if the state has changed
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    // Disable interrupts as this function uses some data changed in the HVIL interrupt task
    noInterrupts();
    contactorData* data = (contactorData*) cData;
    // Close the contactor and turn on the LED if the user asks to close the contactor and the alarms are all not active
    if (*data->contactorFlag == CLOSE && *data->hvilAlarmStatus == NA && *data->ocAlarmStatus == NA && *data->hvoorAlarmStatus == NA) {
        *data->contactorStatus = CONTACTOR_CLOSED;
        digitalWrite(*data->contactorPin, HIGH);
    // Open the contactor and turn off the LED if the user asks to open the contactor or any alarm is active
    } else if (*data->contactorFlag == OPEN || *data->hvilAlarmStatus == AA || *data->hvilAlarmStatus == ANA ||
               *data->ocAlarmStatus == AA || *data->ocAlarmStatus == ANA ||*data->hvoorAlarmStatus == AA || *data->hvoorAlarmStatus == ANA) {
        // If the user didn't ask to open contactors and they were just closed,
        // set the the flag to tell the display task to open them
        if (*data->contactorFlag != OPEN && *data->contactorStatus == CONTACTOR_CLOSED) {
            *data->contactorFlag = OPEN;
        }
        *data->contactorStatus = CONTACTOR_OPEN;
        digitalWrite(*data->contactorPin, LOW);
    }
    // Enable interrupts again
    interrupts();
}
