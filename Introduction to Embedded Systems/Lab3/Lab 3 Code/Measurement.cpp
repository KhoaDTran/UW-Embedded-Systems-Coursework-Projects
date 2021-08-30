#include "Measurement.h"
#include "Arduino.h"

void updateHVIL(bool* hvilReading, const byte pin, bool* hvilChanged) {
    /****************
    * Function name: updateHVIL
    * Function inputs: a pointer to the system's HVIL reading, the HVIL's pin, and a pointer to tell the system the HVIL
    *                  reading changed
    * Function outputs: none
    * Function description: Reads the HVIL of the system and updates the reading and whether or not it changed
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    int newReading = digitalRead(pin);
    if (newReading != *hvilReading) {
        *hvilReading = newReading;
        *hvilChanged = true;
    } else {
        *hvilChanged = false;
    }
}

void updateTemperature(float* temperatureReading, bool* tempChanged, const byte tempPin) {
    /****************
    * Function name: updateTemperature
    * Function inputs: a pointer to the system's temperature reading, a pointer to the temperature change flag,
    * and the pin we're reading the temperature from
    * Function outputs: none
    * Function description: Updates the temperature when the physical temperature changes
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    // Get the new temperature reading and map it from -10C to 45C
    int newTemp = analogRead(tempPin);
    newTemp = map(newTemp, 0, 1023, -10, 45);
    // If the new temperature is different from the old temperature, change the value and set the flag
    if (newTemp != (int) *temperatureReading) {
        *temperatureReading = (float) newTemp;
        *tempChanged = true;
    } else {
        *tempChanged = false;
    }
}

void updateHvCurrent(float* currentReading, bool* currChanged, const byte currPin) {
    /****************
    * Function name: updateHvCurrent
    * Function inputs: a pointer to the system's current reading, a pointer to the current change flag,
    * and the pin we're reading the current from
    * Function outputs: none
    * Function description: Updates the current when the physical current changes
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    // Get the new current reading and map it from -25A to 25A
    int newCurr = analogRead(currPin);
    newCurr = map(newCurr, 0, 1023, -25, 25);
    // If the new current is different from the old current, change the value and set the flag
    if (newCurr != (int) *currentReading) {
        *currentReading = (float) newCurr;
        *currChanged = true;
    } else {
        *currChanged = false;
    }
}

void updateHvVoltage(float* voltageReading, bool* voltChanged, const byte voltPin) {
    /****************
    * Function name: updateHvVoltage
    * Function inputs: a pointer to the system's voltage reading, a pointer to the voltage change flag,
    * and the pin we're reading the voltage from
    * Function outputs: none
    * Function description: Updates the voltage when the physical voltage changes
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    // Get the new voltage reading and map it from 0V to 450V
    int newVolt = analogRead(voltPin);
    newVolt = map(newVolt, 0, 1023, 0, 450);
    // If the new voltage is different from the old voltage, change the value and set the flag
    if (newVolt != (int) *voltageReading) {
        *voltageReading = (float) newVolt;
        *voltChanged = true;
    } else {
        *voltChanged = false;
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
  	updateTemperature(data->temperature, data->tempChanged, *data->tempPin);
  	updateHvCurrent(data->hvCurrent, data->currChanged, *data->currPin);
  	updateHvVoltage(data->hvVoltage, data->voltChanged, *data->voltPin);
}
