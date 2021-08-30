#include "Contactor.h"

void contactorTask(void* cData) {
    /****************
    * Function name: contactorTask
    * Function inputs: void* pointer to the alarmData struct
    * Function outputs: none
    * Function description: Updates the contactor's status and turns on the contactor LED only if the state has changed
    * Author(s): Yasin Alissa
    *****************/
    contactorData* data = (contactorData*) cData;
    // Get the flag that tells us what to do to the contactor
    int flag = *data->contactorFlag;
    // If we should close the contactor, change the state to closed and turn on the LED
    if (flag == CLOSE) {
        *data->contactorStatus = CONTACTOR_CLOSED;
        digitalWrite(*data->contactorPin, HIGH);
    // If we should open the contactor, change the state to open and turn off the LED
    } else if (flag == OPEN) {
        *data->contactorStatus = CONTACTOR_OPEN;
        digitalWrite(*data->contactorPin, LOW);
    }
}
