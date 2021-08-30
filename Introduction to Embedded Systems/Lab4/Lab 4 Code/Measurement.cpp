#include "Measurement.h"
#include "Arduino.h"

void updateHVIL(bool* hvilReading, const byte pin, volatile bool* hvilChanged) {
    /****************
    * Function name: updateHVIL
    * Function inputs: a pointer to the system's HVIL reading, the HVIL's pin, and a pointer to tell the system the HVIL
    * reading changed
    * Function outputs: none
    * Function description: Reads the HVIL of the system and updates the reading and whether or not it changed
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    // Disable interrupts as this function uses some data changed in the HVIL interrupt task
    noInterrupts();
    int newReading = digitalRead(pin);
    if (newReading != *hvilReading) {
        *hvilReading = newReading;
        *hvilChanged = true;
    }
    // Enable interrupts again
    interrupts();
}

void updateTemperature(float* temperatureReading, bool* tempChanged, const byte tempPin, dataLogData* dlData) {
    /****************
    * Function name: updateTemperature
    * Function inputs: a pointer to the system's temperature reading, a pointer to the temperature change flag,
    * the pin we're reading the temperature from, and the data logging data
    * Function outputs: none
    * Function description: Updates the temperature when the physical temperature changes
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    // Get the new temperature reading and map it from -10C to 45C
    int newTemp = analogRead(tempPin);
    newTemp = map(newTemp, 0, 1023, -10, 45);
    // Adjust the minimum temperature if needed
    if (newTemp < *dlData->tempMin || *dlData->tempMin == 0) {
        *dlData->tempMin = newTemp;
        *dlData->tempMinChanged = true;
    } else {
        *dlData->tempMinChanged = false;
    }
    // Adjust the maximum temperature if needed
    if (newTemp > *dlData->tempMax || *dlData->tempMax == 0) {
        *dlData->tempMax = newTemp;
        *dlData->tempMaxChanged = true;
    } else {
        *dlData->tempMaxChanged = false;
    }
    // If the new temperature is different from the old temperature, change the value and set the flag
    if (newTemp != (int) *temperatureReading) {
        *temperatureReading = (float) newTemp;
        *tempChanged = true;
    }
}

void updateHvCurrent(float* currentReading, bool* currChanged, const byte currPin, dataLogData* dlData) {
    /****************
    * Function name: updateHvCurrent
    * Function inputs: a pointer to the system's current reading, a pointer to the current change flag,
    * the pin we're reading the current from, and the data logging data
    * Function outputs: none
    * Function description: Updates the current when the physical current changes
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    // Get the new current reading and map it from -25A to 25A
    int newCurr = analogRead(currPin);
    newCurr = map(newCurr, 0, 1023, -25, 25);
    // Adjust the minimum current if needed
    if (newCurr < *dlData->currMin|| *dlData->currMin == 0) {
        *dlData->currMin = newCurr;
        *dlData->currMinChanged = true;
    } else {
        *dlData->currMinChanged = false;
    }
    // Adjust the maximum current if needed
    if (newCurr > *dlData->currMax|| *dlData->currMax == 0) {
        *dlData->currMax = newCurr;
        *dlData->currMaxChanged = true;
    } else {
        *dlData->currMaxChanged = false;
    }
    // If the new current is different from the old current, change the value and set the flag
    if (newCurr != (int) *currentReading) {
        *currentReading = (float) newCurr;
        *currChanged = true;
    }
}

void updateHvVoltage(float* voltageReading, bool* voltChanged, const byte voltPin, dataLogData* dlData) {
    /****************
    * Function name: updateHvVoltage
    * Function inputs: a pointer to the system's voltage reading, a pointer to the voltage change flag,
    * the pin we're reading the voltage from, and the data logging data
    * Function outputs: none
    * Function description: Updates the voltage when the physical voltage changes
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    // Get the new voltage reading and map it from 0V to 450V
    int newVolt = analogRead(voltPin);
    newVolt = map(newVolt, 0, 1023, 0, 450);
    // Adjust the minimum voltage if needed
    if (newVolt < *dlData->voltMin || *dlData->voltMin == -1) {
        *dlData->voltMin = newVolt;
        *dlData->voltMinChanged = true;
    } else {
        *dlData->voltMinChanged = false;
    }
    // Adjust the maximum voltage if needed
    if (newVolt > *dlData->voltMax|| *dlData->voltMin == -1) {
        *dlData->voltMax = newVolt;
        *dlData->voltMaxChanged = true;
    } else {
        *dlData->voltMaxChanged = false;
    }
    // If the new voltage is different from the old voltage, change the value and set the flag
    if (newVolt != (int) *voltageReading) {
        *voltageReading = (float) newVolt;
        *voltChanged = true;
    }
}

void measurementTask(void* mData) {
    /****************
    * Function name: measurementTask
    * Function inputs: void* pointer to the measurementData struct
    * Function outputs: none
    * Function description: Updates all measurement statuses at their respective update rates
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
  	measurementData* data = (measurementData*) mData;
  	// Update statuses for all measurements
  	updateHVIL(data->hvilStatus, *data->hvilPin, data->hvilChanged);
  	updateTemperature(data->temperature, data->tempChanged, *data->tempPin, data->dlData);
  	updateHvCurrent(data->hvCurrent, data->currChanged, *data->currPin, data->dlData);
  	updateHvVoltage(data->hvVoltage, data->voltChanged, *data->voltPin, data->dlData);
  	// Reset the measurement history if the user asked for a reset
    if (*data->dlData->resetFlag) {
        resetMeasurementHistory(data->dlData);
    }
}
