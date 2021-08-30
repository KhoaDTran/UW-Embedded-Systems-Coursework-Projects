#include "Measurement.h"

void updateHVIL(bool* hvilReading, const byte pin, bool* hvilChanged) {
    /****************
    * Function name: updateHVIL
    * Function inputs: a pointer to the system's HVIL reading, the HVIL's pin, and a pointer to tell the system the HVIL
    *                  reading changed
    * Function outputs: none
    * Function description: Reads the HVIL of the system and updates the reading and whether or not it changed
    * Author(s): Yasin Alissa
    *****************/
    bool newReading = digitalRead(pin);
    if (newReading != *hvilReading) {
        *hvilReading = newReading;
        *hvilChanged = true;
    } else {
        *hvilChanged = false;
    }
}

void updateTemperature(float* temperatureReading, int seconds) {
    /****************
    * Function name: updateTemperature
    * Function inputs: a pointer to the system's temperature reading and the seconds since the system started
    * Function outputs: none
    * Function description: Updates the temperature once per second
    * Author(s): Yasin Alissa
    *****************/
    // The temperature values we cycle through
    float temps[3] = {-10, 5, 25};
    // Update every second
    *temperatureReading = temps[seconds % 3];
}

void updateHvCurrent(float* currentReading, int seconds) {
    /****************
    * Function name: updateHvCurrent
    * Function inputs: a pointer to the system's current reading and the seconds since the system started
    * Function outputs: none
    * Function description: Updates the HV Current once per two seconds
    * Author(s): Yasin Alissa
    *****************/
    // The current values we cycle through
    float currs[3] = {-20, 0, 20};
    // Only update every two seconds
    if (seconds % 2 == 0) {
        *currentReading = currs[(seconds % 6) / 2];
    }
}

void updateHvVoltage(float* voltageReading, int seconds) {
    /****************
    * Function name: updateHvVoltage
    * Function inputs: a pointer to the system's voltage reading and the seconds since the system started
    * Function outputs: none
    * Function description: Updates the HV Voltage once per three seconds
    * Author(s): Yasin Alissa
    *****************/
    // The voltage values we cycle through
    float volts[3] = {10, 150, 450};
    // Only update every three seconds
    if (seconds % 3 == 0) {
        *voltageReading = volts[(seconds % 9) / 3];
    }
}

void measurementTask(void* mData) {
    /****************
    * Function name: measurementTask
    * Function inputs: void* pointer to the measurementData struct
    * Function outputs: none
    * Function description: Updates all measurement statuses at their respective update rates
    * Author(s): Yasin Alissa
    *****************/
  	measurementData* data = (measurementData*) mData;
    // Read-only value so we don't need the pointer
    int seconds = *data->seconds;
  	// Update statuses for all measurements
  	updateHVIL(data->hvilStatus, *data->hvilPin, data->hvilChanged);
  	updateTemperature(data->temperature, seconds);
  	updateHvCurrent(data->hvCurrent, seconds);
  	updateHvVoltage(data->hvVoltage, seconds);
}
