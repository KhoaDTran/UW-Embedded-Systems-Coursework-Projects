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
    contactorData* data = (contactorData*) cData;
    // Close the contactor and turn on the LED if the user asks to close the contactor and the HVIL alarm is not active
    if (*data->contactorFlag == CLOSE && *data->hvilAlarmStatus == NA) {
        *data->contactorStatus = CONTACTOR_CLOSED;
        digitalWrite(*data->contactorPin, HIGH);
    // Open the contactor and turn off the LED if the user asks to open the contactor or the HVIL alarm is active
    } else if (*data->contactorFlag == OPEN || *data->hvilAlarmStatus == AA || *data->hvilAlarmStatus == ANA) {
        // If the user didn't ask to open contactors and they were just closed,
        // set the the flag to tell the display task to open them
        if (*data->contactorFlag != OPEN && *data->contactorStatus == CONTACTOR_CLOSED) {
            *data->contactorFlag = OPEN;
        }
        *data->contactorStatus = CONTACTOR_OPEN;
        digitalWrite(*data->contactorPin, LOW);
    }
}
