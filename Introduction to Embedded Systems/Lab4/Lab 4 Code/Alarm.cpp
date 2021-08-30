#include "Alarm.h"
#include "Measurement.h"
#include "Arduino.h"

void updateHVILAlarm(int* hvilAlarmStatus, bool* hvilAlarmChanged, bool hvilStatus, bool* hvilAcknowledged, volatile bool* ISRFlag) {
    /****************
    * Function name: updateHVILAlarm
    * Function inputs: the status of the HVIL alarm, the HVIL alarm change flag, the current HVIL status,
    * whether or not the alarms have been acknowledged, and a flag for when the HVIL ISR runs
    * Function outputs: none
    * Function description: Updates the HVIL alarm's status per the spec
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    // Disable interrupts as this function uses some data changed in the HVIL interrupt task
    noInterrupts();
    // Reset the HVIL ISR flag
    *ISRFlag = false;
    int newStatus = *hvilAlarmStatus;
    // If the HVIL is closed, the alarm is not active
    if (hvilStatus == HVIL_CLOSED) {
        newStatus = NA;
        *hvilAcknowledged = false;
    } else {
        // If the HVIL is open and the alarm has been acknowledged, the alarm is active and acknowledged
        if ((*hvilAcknowledged)) {
            newStatus = AA;
        }
        // HVIL interrupt routine handles "active, not acknowledged" assignment
    }
    // If the new status is not the same as the old status, changed the status and set the change flag. Otherwise, set
    // the flag to indicate that there has been no change
    if (newStatus != *hvilAlarmStatus) {
        *hvilAlarmStatus = newStatus;
        *hvilAlarmChanged = true;
    }
    // Enable interrupts again
    interrupts();
}

void updateOvercurrentAlarm(int* overcurrentStatus, bool* overcurrentAlarmChanged, float hvCurrent, bool* ocAcknowledged) {
    /****************
    * Function name: updateOvercurrentAlarm
    * Function inputs: the status of the overcurrent alarm, the overcurrent alarm change flag, the current value,
    * and whether or not the alarms have been acknowledged
    * Function outputs: none
    * Function description: Updates the overcurrent alarm's status per the spec
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    int newStatus;
    // If the current value is between -5A and 20A, the alarm is not active
    if (hvCurrent > -5.0 && hvCurrent < 20.0) {
        newStatus = NA;
        *ocAcknowledged = false;
    } else {
        // If the current value is not between -5A and 20A and the alarm hasn't been acknowledged,
        // the alarm is active and not acknowledged
        if (!(*ocAcknowledged)) {
            newStatus = ANA;
        // If the current value is not between -5A and 20A and the alarm has been acknowledged,
        // the alarm is active and acknowledged
        } else {
            newStatus = AA;
        }
    }
    // If the new status is not the same as the old status, changed the status and set the change flag. Otherwise, set
    // the flag to indicate that there has been no change
    if (newStatus != *overcurrentStatus) {
        *overcurrentStatus = newStatus;
        *overcurrentAlarmChanged = true;
    }
}

void updateHvOutOfRangeAlarm(int* hvoorStatus, bool* hvoorAlarmChanged, float hvVoltage, bool* hvoorAcknowledged) {
    /****************
    * Function name: updateHvOutOfRangeAlarm
    * Function inputs: the status of the HVOOR alarm, the HVOOR alarm change flag, the current voltage status,
    * and whether or not the alarms have been acknowledged
    * Function outputs: none
    * Function description: Updates the HVOOR alarm's status per the spec
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    int newStatus;
    // If the voltage value is between 280V and 405V, the alarm is not active
    if (hvVoltage > 280.0 && hvVoltage < 405.0) {
        newStatus = NA;
        *hvoorAcknowledged = false;
    } else {
        // If the voltage value is not between 280V and 405V and the alarm hasn't been acknowledged,
        // the alarm is active and not acknowledged
        if (!(*hvoorAcknowledged)) {
            newStatus = ANA;
            // If the voltage value is not between 280V and 405V and the alarm has been acknowledged,
            // the alarm is active and acknowledged
        } else {
            newStatus = AA;
        }
    }
    // If the new status is not the same as the old status, changed the status and set the change flag. Otherwise, set
    // the flag to indicate that there has been no change
    if (newStatus != *hvoorStatus) {
        *hvoorStatus = newStatus;
        *hvoorAlarmChanged = true;
    }
}

void alarmTask(void* aData) {
    /****************
    * Function name: alarmTask
    * Function inputs: void* pointer to the alarmData struct
    * Function outputs: none
    * Function description: Updates all alarm statuses at their respective update rates
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    alarmData* data = (alarmData*) aData;
    // Update statuses for all alarms
    updateHVILAlarm(data->hvilAlarmStatus, data->hvilAlarmChanged, *data->hvilStatus, data->hvilAcknowledged, data->ISRFlag);
    updateOvercurrentAlarm(data->overcurrentStatus, data->overcurrentAlarmChanged, *data->hvCurrent, data->ocAcknowledged);
    updateHvOutOfRangeAlarm(data->hvoorStatus, data->hvoorAlarmChanged, *data->hvVoltage, data->hvoorAcknowledged);
}
