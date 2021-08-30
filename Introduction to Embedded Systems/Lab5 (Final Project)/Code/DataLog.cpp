#include "DataLog.h"

void writeToEEPROM(float* value, int valueAddr) {
    /****************
    * Function name: writeToEEPROM
    * Function inputs: pointer to the float we want to write to EEPROM and the address in EEPROM we're writing to
    * Function outputs: none
    * Function description: Writes the given float into EEPROM at the given address
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    // Cast the value float to a 4-byte array of bytes as floats are 4 bytes long
    byte* valueBytes = (byte*)value;
    // Write the new value to EEPROM at the correct address byte by byte
    for (int i = 0; i < 4; i++) {
        EEPROM.write(valueAddr + i, valueBytes[i]);
    }
}

float readFromEEPROM(int valueAddr) {
    /****************
    * Function name: readFromEEPROM
    * Function inputs: the address in EEPROM we're reading from
    * Function outputs: none
    * Function description: Reads a float from EEPROM at the given address
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    byte* valueBytes;
    for (int i = 0; i < 4; i++) {
        valueBytes[i] = EEPROM.read(valueAddr + i);
    }
    return *((float*) valueBytes);
}

void resetMeasurementHistory(dataLogData* data) {
    /****************
    * Function name: resetMeasurementHistory
    * Function inputs: pointer to our data logging data
    * Function outputs: none
    * Function description: Resets the system's measurement history saved in EEPROM
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    float zero = 0.0;
    float neg1 = -1.0;
    // Set the temperature min and max to 0
    writeToEEPROM(&zero, *data->tempMinAddr);
    *data->tempMin = zero;
    *data->tempMax = zero;
    writeToEEPROM(&zero, *data->tempMaxAddr);
    // Set the current min and max to 0
    writeToEEPROM(&zero, *data->currMinAddr);
    writeToEEPROM(&zero, *data->currMaxAddr);
    *data->currMin = zero;
    *data->currMax = zero;
    // Set the voltage min and max to -1
    writeToEEPROM(&neg1, *data->voltMinAddr);
    writeToEEPROM(&neg1, *data->voltMaxAddr);
    *data->voltMin = neg1;
    *data->voltMax = neg1;
    *data->resetFlag = false;
}

void dataLogTask (void* dlData) {
    /****************
    * Function name: dataLogTask
    * Function inputs: void* pointer to the dataLogData struct
    * Function outputs: none
    * Function description: Performs our data logging for the battery management system
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    dataLogData* data = (dataLogData*) dlData;
    // Reset the values if the reset flag is set
    if (*data->resetFlag) {
        resetMeasurementHistory(data);
    // If we just reset the values, we don't want to override the newly-reset values
    } else {
        // Write the new minimum temperature to EEPROM if it changed
        if (*data->tempMinChanged) {
            // Write the new value to EEPROM
            writeToEEPROM(data->tempMin, *data->tempMinAddr);
            // Reset the flag
            *data->tempMinChanged = false;
        }
        // Write the new maximum temperature to EEPROM if it changed
        if (*data->tempMaxChanged) {
            // Write the new value to EEPROM
            writeToEEPROM(data->tempMax, *data->tempMaxAddr);
            // Reset the flag
            *data->tempMaxChanged = false;
        }
        // Write the new minimum current to EEPROM if it changed
        if (*data->currMinChanged) {
            // Write the new value to EEPROM
            writeToEEPROM(data->currMin, *data->currMinAddr);
            // Reset the flag
            *data->currMinChanged = false;
        }
        // Write the new maximum current to EEPROM if it changed
        if (*data->currMaxChanged) {
            // Write the new value to EEPROM
            writeToEEPROM(data->currMax, *data->currMaxAddr);
            // Reset the flag
            *data->currMaxChanged = false;
        }
        // Write the new minimum voltage to EEPROM if it changed
        if (*data->voltMinChanged) {
            // Write the new value to EEPROM
            writeToEEPROM(data->voltMin, *data->voltMinAddr);
            // Reset the flag
            *data->voltMinChanged = false;
        }
        // Write the new maximum voltage to EEPROM if it changed
        if (*data->voltMaxChanged) {
            // Write the new value to EEPROM
            writeToEEPROM(data->voltMax, *data->voltMaxAddr);
            // Reset the flag
            *data->voltMaxChanged = false;
        }
    }
}