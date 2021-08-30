#include "Alarm.h"

// The available statuses for the alarms that we cycle through
const char* alarmStatuses[3] = {"NOT ACTIVE", "ACTIVE, NOT ACKNOWLEDGED", "ACTIVE, ACKNOWLEDGED"};

void updateHVILAlarm(char** hvilAlarmStatus, int seconds) {
    /****************
    * Function name: updateHVILAlarm
    * Function inputs: the status of the HVIL alarm, seconds since we started the battery management system
    * Function outputs: none
    * Function description: Updates the HVIL alarm's status once per second
    * Author(s): Yasin Alissa
    *****************/
    *hvilAlarmStatus = alarmStatuses[seconds % 3];
}

void updateOvercurrentAlarm(char** overcurrentStatus, int seconds) {
    /****************
    * Function name: updateOvercurrentAlarm
    * Function inputs: the status of the overcurrent alarm, seconds since we started the battery management system
    * Function outputs: none
    * Function description: Updates the overcurrent alarm's status once per two seconds
    * Author(s): Yasin Alissa
    *****************/
    if (seconds % 2 == 0) {
        *overcurrentStatus = alarmStatuses[(seconds % 6) / 2];
    }
}

void updateHvOutOfRangeAlarm(char** hvOutOfRangeStatus, int seconds) {
    /****************
    * Function name: updateHvOutOfRangeAlarm
    * Function inputs: the status of the HVOOR alarm, seconds since we started the battery management system
    * Function outputs: none
    * Function description: Updates the HVOOR alarm's status once per three seconds
    * Author(s): Yasin Alissa
    *****************/
    if (seconds % 3 == 0) {
        *hvOutOfRangeStatus = alarmStatuses[(seconds % 9) / 3];
    }
}

void alarmTask(void* aData) {
    /****************
    * Function name: alarmTask
    * Function inputs: void* pointer to the alarmData struct
    * Function outputs: none
    * Function description: Updates all alarm statuses at their respective update rates
    * Author(s): Yasin Alissa
    *****************/
    alarmData* data = (alarmData*) aData;
    // Read-only value so we don't need the pointer
    int seconds = *data->seconds;
    // Update statuses for all alarms
    updateHVILAlarm(data->hvilAlarmStatus, seconds);
    updateOvercurrentAlarm(data->overcurrentStatus, seconds);
    updateHvOutOfRangeAlarm(data->hvOutOfRangeStatus, seconds);
}
