#include "SOC.h"
#include "Arduino.h"

const float table[4][5] = {{0.0, 10.0, 35.0, 100.0, 100.0}, {0.0, 0.0 ,20.0, 80.0, 100.0}, {0.0, 0.0, 10.0, 60.0, 100.0},
                           {0.0, 0.0, 0.0, 50.0, 100.0}};
const float temps[4] = {-10.0, 0.0, 25.0, 45.0};
const float ocVoltages[5] = {200.0, 250.0, 300.0, 350.0, 400.0};

float interpolate(int tempIndex, int voltageIndex, float temp, float voltage) {
    /****************
    * Function name: interpolate
    * Function inputs: the lower index to lookup in our temperature table, the lower index to lookup in our voltage table,
    * the current temperature, and the current open circuit voltage
    * Function outputs: none
    * Function description: Calculates a 2-d interpolation based on the given indices and values
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    // Pull our values from our lookup table
    float t1v1 = table[tempIndex][voltageIndex];
    float t1v2 = table[tempIndex][voltageIndex + 1];
    float t2v1 = table[tempIndex + 1][voltageIndex];
    float t2v2 = table[tempIndex + 1][voltageIndex + 1];
    float v1 = ocVoltages[voltageIndex];
    float v2 = ocVoltages[voltageIndex + 1];
    float t1 = temps[tempIndex];
    float t2 = temps[tempIndex + 1];
    // Interpolate on the temperature axis twice
    float c1 = t1v1 + ((temp - t1) * ((t2v1 - t1v1) / (t2 - t1)));
    float c2 = t1v2 + ((temp - t1) * ((t2v2 - t1v2) / (t2 - t1)));
    // Interpolate once on the voltage axis using the calculated charges from the temperature axis to find the new charge
    float newCharge = c1 + ((voltage - v1) * ((c2 - c1) / (v2 - v1)));
    return newCharge;
}

void socTask(void* sData) {
    /****************
    * Function name: socTask
    * Function inputs: void* pointer to the socData struct
    * Function outputs: none
    * Function description: Sets SOC state based on our 2d-interpolation table
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    socData* data = (socData*) sData;
    // Calculate the open circuit voltage
    float ocVoltage = *data->voltage + (0.5 * *data->current);
    // Initialize a variable for our new charge
    float newCharge = 0.0;
    // Set the new charge to the correct values for edge cases
    if (ocVoltage <= 200.0) {
        newCharge = 0.0;
    } else if (ocVoltage >= 400.0) {
        newCharge = 100.0;
    } else {
        int voltageIndex, tempIndex;
        float temp = *data->temperature;
        // Find our temperature table lower index for interpolation
        for (int i = 0; i < 3; i++) {
            if (temp <= temps[i + 1]) {
                tempIndex = i;
                break;
            }
        }
        // Find our open circuit voltage table lower index for interpolation
        for (int i = 0; i < 4; i++) {
            if (ocVoltage <= ocVoltages[i + 1]) {
                voltageIndex = i;
                break;
            }
        }
        // Use interpolation to calculate the new charge
        newCharge = interpolate(tempIndex, voltageIndex, temp, ocVoltage);
    }
    // If the new charge is different from the old charge, set the change flag and change the charge value
    if (newCharge != *data->charge) {
        *data->socChanged = true;
        *data->charge = newCharge;
    }
}
