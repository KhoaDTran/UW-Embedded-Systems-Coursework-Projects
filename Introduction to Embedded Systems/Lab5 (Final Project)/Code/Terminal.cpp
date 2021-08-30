#include "Terminal.h"
#include "Arduino.h"

void terminalTask (void* tData) {
    /****************
    * Function name: terminalTask
    * Function inputs: void* pointer to the terminalData struct
    * Function outputs: none
    * Function description: Takes user's input from the remote terminal and does what the user asks
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    terminalData* data = (terminalData*) tData;
    // Read an integer value from Serial0
    int userInput = Serial.parseInt();
    // Terminate if no user input is read
    if (userInput == 0) {
        return;
    }
    // If the user wants to reset the measurement history, set the appropriate flag
    if (userInput == 1) {
        *data->resetFlag = true;
    }
    // If the user wants the current range, print it out
    if (userInput == 2) {
        Serial.print("HV Current Range: [");
        Serial.print(*data->currMax);
        Serial.print(", ");
        Serial.print(*data->currMin);
        Serial.println("]");
    }
    // If the user wants the voltage range, print it out
    if (userInput == 3) {
        Serial.print("HV Voltage Range: [");
        Serial.print(*data->voltMax);
        Serial.print(", ");
        Serial.print(*data->voltMin);
        Serial.println("]");
    }
    // If the user wants the temperature range, print it out
    if (userInput == 4) {
        Serial.print("Temperature Range: [");
        Serial.print(*data->tempMax);
        Serial.print(", ");
        Serial.print(*data->tempMin);
        Serial.println("]");
    }
}
