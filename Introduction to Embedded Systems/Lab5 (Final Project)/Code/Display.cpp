#include "Display.h"
#include "Colors.h"
#include <string.h>

const char* alarmStatuses[3] = {"NOT ACTIVE", "ACTIVE, NOT ACKNOWLEDGED", "ACTIVE, ACKNOWLEDGED"};

void buttons(Elegoo_TFTLCD tft) {
    /****************
    * Function name: buttons
    * Function inputs: the TFT screen
    * Function outputs: none
    * Function description: Sets up the page-change buttons. Only runs at startup
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    tft.fillScreen(WHITE);
    tft.fillRect(0, 240, 240, 80, BLACK);
    tft.fillRect(0, 240, 240, 5, BLUE);
    Elegoo_GFX_Button mButton, aButton, bButton, acButton;
    mButton.initButton(&tft, 33, 278, 50, 45, WHITE, BLUE, WHITE, "Measure", 1);
    mButton.drawButton();
    aButton.initButton(&tft, 91, 278, 50, 45, WHITE, BLUE, WHITE, "Alarm", 1);
    aButton.drawButton();
    bButton.initButton(&tft, 149, 278, 50, 45, WHITE, BLUE, WHITE, "Battery", 1);
    bButton.drawButton();
    acButton.initButton(&tft, 207, 278, 50, 45, WHITE, BLUE, WHITE, "Accel.", 1);
    acButton.drawButton();
}

void measurePage(Elegoo_TFTLCD tft, bool newScreen, measurementData mData, socData sData) {
    /****************
    * Function name: measurePage
    * Function inputs: the TFT screen, an indicator if we just switched to this screen, the measurementData struct,
    *                  and the socData struct
    * Function outputs: none
    * Function description: Updates the display for the measurement screen at each measurement's respective rate. Also
    *                       sets the screen up if we just switched to it
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    // Only do this if we just switched to the measurement screen
    if (newScreen) {
        // Clear old screen
        tft.fillRect(0, 0, 240, 240, WHITE);

        // Draw the title
        tft.setCursor(10, 10);
        tft.setTextColor(BLACK);
        tft.setTextSize(2);
        tft.print("Measurement");
        tft.fillRect(10, 28, 220, 5, BLUE);

        // Draw the bullet points
        for (int x = 0; x < 5; x++) {
            tft.fillCircle(10, 60 + (30 * x), 2, BLUE);
        }

        // Draw labels for each measurement we have
        tft.setTextSize(1);
        tft.setCursor(20, 58);
        tft.print("State of Charge:");
        tft.setCursor(20, 88);
        tft.print("Temperature (");
        int degreeSymbol = 247;
        tft.print((char) degreeSymbol);
        tft.print("C):");
        tft.setCursor(20, 118);
        tft.print("HV Current (A):");
        tft.setCursor(20, 148);
        tft.print("HV Voltage (V):");
        tft.setCursor(20, 178);
        tft.print("HVIL Status:");

    }

    tft.setTextColor(BLACK);
    tft.setTextSize(1);

    // Update the SOC--- if the SOC changed or if we just switched to this screen
    if (*sData.socChanged || newScreen) {
        tft.fillRect(150, 43, 90, 30, WHITE);
        tft.setCursor(150, 58);
        tft.print(*sData.charge);
        *sData.socChanged = false;
    }

    // Update the Temperature State --- if the temperature changed or if we just switched to this screen
    if (*mData.tempChanged || newScreen) {
        tft.fillRect(150, 73, 90, 30, WHITE);
        tft.setCursor(150, 88);
        tft.print(*mData.temperature);
        *mData.tempChanged = false;
    }


    // Update the Current State --- if the current changed or if we just switched to this screen
    if (*mData.currChanged || newScreen) {
        tft.fillRect(150, 103, 90, 30, WHITE);
        tft.setCursor(150, 118);
        tft.print(*mData.hvCurrent);
        *mData.currChanged = false;
    }

    // Update the Voltage State --- if the voltage changed or if we just switched to this screen
    if (*mData.voltChanged || newScreen) {
        tft.fillRect(150, 133, 90, 30, WHITE);
        tft.setCursor(150, 148);
        tft.print(*mData.hvVoltage);
        *mData.voltChanged = false;
    }

    // Update the HVIL Status -- only on physical change in the system or if we just switched to this screen
    if (*mData.hvilChanged || newScreen) {
        tft.fillRect(150, 163, 90, 30, WHITE);
        tft.setCursor(150, 178);
        if (*mData.hvilStatus == true) {
            tft.print("OPEN");
        } else {
            tft.print("CLOSED");
        }
        *mData.hvilChanged = false;
    }


}

void alarmPage(Elegoo_TFTLCD tft, bool newScreen, alarmData aData, bool* buttonDrawn) {
    /****************
    * Function name: alarmPage
    * Function inputs: the TFT screen, an indicator if we just switched to this screen, and the alarmData struct,
    * Function outputs: none
    * Function description: Updates the display for the alarm screen at each alarm's respective rate. Also sets
    *                       the screen up if we just switched to it
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    // Only do this if we just switched to the alarm screen
    if (newScreen) {
        // Clear old screen
        tft.fillRect(0, 0, 240, 240, WHITE);

        // Draw the title
        tft.setCursor(10, 10);
        tft.setTextColor(BLACK);
        tft.setTextSize(2);
        tft.print("Alarm");
        tft.fillRect(10, 28, 220, 5, BLUE);

        // Draw the bullet points
        for (int x = 0; x < 3; x++) {
            tft.fillCircle(10, 60 + (30 * x), 2, BLUE);
        }

        // Draw the labels for each alarm we have
        tft.setTextSize(1);
        tft.setCursor(20, 58);
        tft.print("HVIL Alarm:");
        tft.setCursor(20, 88);
        tft.print("Overcurrent:");
        tft.setCursor(20, 118);
        tft.print("HVOOR Alarm:");
    }

    // Draw the button to acknowledge alarms if we don't already have it drawn and
    // if there is at least one that needs acknowledging
    bool alarmsToAcknowledge = *aData.hvilAlarmStatus == ANA || *aData.overcurrentStatus == ANA || *aData.hvoorStatus == ANA;
    if (!(*buttonDrawn) && alarmsToAcknowledge) {
        tft.setCursor(10, 140);
        tft.setTextColor(BLACK);
        tft.setTextSize(2);
        tft.print("Acknowledge Alarms");
        tft.fillRect(10, 158, 220, 5, BLUE);
        Elegoo_GFX_Button ackButton;
        ackButton.initButton(&tft, 120, 195, 188, 45, BLACK, BLUE, WHITE, "ACKNOWLEDGE", 1);
        ackButton.drawButton();
        *buttonDrawn = true;
    } else {
        if (!alarmsToAcknowledge) {
            tft.fillRect(0, 140, 240, 100, WHITE);
            *buttonDrawn = false;
        }
    }

    tft.setTextColor(BLACK);
    tft.setTextSize(1);

    // Update the HVIL Alarm Status --- if the HVIL alarm changed or if we just switched to this screen
    if (*aData.hvilAlarmChanged || newScreen) {
        tft.fillRect(95, 43, 145, 30, WHITE);
        tft.setCursor(95, 58);
        tft.print(alarmStatuses[*aData.hvilAlarmStatus]);
        *aData.hvilAlarmChanged = false;
    }

    // Update the Overcurrent Alarm Status --- if the overcurrent alarm changed or if we just switched to this screen
    if (*aData.overcurrentAlarmChanged || newScreen) {
        tft.fillRect(95, 73, 145, 30, WHITE);
        tft.setCursor(95, 88);
        tft.print(alarmStatuses[*aData.overcurrentStatus]);
        *aData.overcurrentAlarmChanged = false;
    }

    // Update the HVOOR Alarm Status --- if the HVOOR alarm changed or if we just switched to this screen
    if (*aData.hvoorAlarmChanged || newScreen) {
        tft.fillRect(95, 103, 145, 30, WHITE);
        tft.setCursor(95, 118);
        tft.print(alarmStatuses[*aData.hvoorStatus]);
        *aData.hvoorAlarmChanged = false;
    }
}

void batteryPage(Elegoo_TFTLCD tft, bool newScreen, contactorData cData) {
    /****************
    * Function name: batteryPage
    * Function inputs: the TFT screen, an indicator if we just switched to this screen, and the contactorData struct
    * Function outputs: none
    * Function description: Updates the display for the battery on/off screen if there is a change needed. Also sets
    *                       the screen up if we just switched to it
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    // Only do this if we just switched to the battery screen
    if (newScreen) {
        // Clear old screen
        tft.fillRect(0, 0, 240, 240, WHITE);

        // Draw the title on the screen
        tft.setCursor(10, 10);
        tft.setTextColor(BLACK);
        tft.setTextSize(2);
        tft.print("Contactor");
        tft.fillRect(10, 28, 220, 5, BLUE);

        // Draw the bullet point
        tft.fillCircle(10, 60, 2, BLUE);

        // Draw the label for the status
        tft.setTextSize(1);
        tft.setCursor(20, 58);
        tft.print("Contactor Status:");

        // Draw the buttons to turn battery on and off
        tft.setCursor(10, 130);
        tft.setTextColor(BLACK);
        tft.setTextSize(2);
        tft.print("Battery ON/OFF");
        tft.fillRect(10, 148, 220, 5, BLUE);
        Elegoo_GFX_Button onButton, offButton;
        onButton.initButton(&tft, 60, 195, 68, 45, BLACK, BLUE, WHITE, "ON", 1);
        onButton.drawButton();
        offButton.initButton(&tft, 180, 195, 68, 45, BLACK, BLUE, WHITE, "OFF", 1);
        offButton.drawButton();
    }

    tft.setTextColor(BLACK);
    tft.setTextSize(1);

    // Update the contactor status --- Only change if the flag is for a change
    // or this is a new screen
    if (*cData.contactorFlag != UNCHANGED_CONT || newScreen) {
        tft.fillRect(180, 43, 120, 30, WHITE);
        tft.setCursor(180, 58);
        if (*cData.contactorStatus == CONTACTOR_OPEN) {
            tft.print("OPEN");
        } else {
            tft.print("CLOSED");
        }
        *cData.contactorFlag = UNCHANGED_CONT;
    }

}

void accelerometerPage(Elegoo_TFTLCD tft, bool newScreen, accelerometerData acData) {
    // Only do this if we just switched to the accelerometer screen
    if (newScreen) {
        // Clear old screen
        tft.fillRect(0, 0, 240, 240, WHITE);

        // Draw the title on the screen
        tft.setCursor(10, 10);
        tft.setTextColor(BLACK);
        tft.setTextSize(2);
        tft.print("Accelerometer");
        tft.fillRect(10, 28, 220, 5, BLUE);

        // Draw the bullet points
        for (int x = 0; x < 3; x++) {
            tft.fillCircle(10, 60 + (30 * x), 2, BLUE);
        }

        // Draw the labels for each measurement we have
        tft.setTextSize(1);
        tft.setCursor(20, 58);
        tft.print("Relative position (cm):");
        tft.setCursor(20, 88);
        tft.print("Total distance traveled (cm):");
        tft.setCursor(20, 118);
        tft.print("Static angle (");
        int degreeSymbol = 247;
        tft.print((char) degreeSymbol);
        tft.print("):");
    }

    tft.setTextColor(BLACK);
    tft.setTextSize(1);

    // Update the relative position at each axis
    tft.fillRect(15, 73, 240, 15, WHITE);
    tft.setCursor(20, 73);
    tft.print(*acData.currXPos);
    tft.print(", ");
    tft.print(*acData.currYPos);
    tft.print(", ");
    tft.print(*acData.currZPos);

    // Update the total distance travelled
    tft.fillRect(15, 103, 240, 15, WHITE);
    tft.setCursor(20, 103);
    tft.print(*acData.totalDist);

    // Update the static angle w.r.t. gravity at each axis
    tft.fillRect(15, 133, 240, 15, WHITE);
    tft.setCursor(20, 133);
    tft.print(*acData.currXAng);
    tft.print(", ");
    tft.print(*acData.currYAng);
    tft.print(", ");
    tft.print(*acData.currZAng);
}

void displayTask(void* dData) {
    /****************
    * Function name: displayTask
    * Function inputs: void* pointer to the displayData struct
    * Function outputs: none
    * Function description: Updates all the values of each page's statuses at their respective rates
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    displayData* data = (displayData*) dData;
    // If we just started the system, draw the buttons on the screen
    if (*data->oldPage == STARTUP) {
        buttons(*data->tft);
    }
    // This tells us if we just switched to this screen
    bool newScreen = (*data->oldPage != *data->currPage);
    // Run this method only if we're currently on the measurement page
    if (*data->currPage == MEASURE_PAGE) {
        measurePage(*data->tft, newScreen, *data->mData, *data->sData);
    // Run this method only if we're currently on the alarms page
    } else if (*data->currPage == ALARM_PAGE) {
        // This method uses volatile variables, so we have to make sure no interrupts happen while it's running
        noInterrupts();
        alarmPage(*data->tft, newScreen, *data->aData, data->alarmButtonDrawn);
        interrupts();
    // Run this method only if we're currently on the battery on/off page
    } else if (*data->currPage == BATTERY_PAGE) {
        batteryPage(*data->tft, newScreen, *data->cData);
        // Run this method only if we're currently on the accelerometer page
    } else if (*data->currPage == ACCELEROMETER_PAGE) {
        accelerometerPage(*data->tft, newScreen, *data->acData);
    }
    // Set the old page to the current page for the next cycle
    *data->oldPage = *data->currPage;
}
