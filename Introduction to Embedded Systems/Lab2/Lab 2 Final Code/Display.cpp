#include "Display.h"
#include "Colors.h"

void buttons(Elegoo_TFTLCD tft) {
    /****************
    * Function name: buttons
    * Function inputs: the TFT screen
    * Function outputs: none
    * Function description: Sets up the page-change buttons. Only runs at startup
    * Author(s): Yasin Alissa
    *****************/
    tft.fillRect(0, 240, 240, 80, BLACK);
    tft.fillRect(0, 240, 240, 5, BLUE);
    Elegoo_GFX_Button mButton, aButton, bButton;
    mButton.initButton(&tft, 43, 278, 68, 45, WHITE, BLUE, WHITE, "Measure", 1);
    mButton.drawButton();
    aButton.initButton(&tft, 120, 278, 68, 45, WHITE, BLUE, WHITE, "Alarm", 1);
    aButton.drawButton();
    bButton.initButton(&tft, 197, 278, 68, 45, WHITE, BLUE, WHITE, "Battery", 1);
    bButton.drawButton();
}

void measurePage(Elegoo_TFTLCD tft, bool newScreen, measurementData mData, socData sData, int seconds) {
    /****************
    * Function name: measurePage
    * Function inputs: the TFT screen, an indicator if we just switched to this screen, the measurementData struct,
    *                  the socData struct, and the seconds elapsed since we started running the system
    * Function outputs: none
    * Function description: Updates the display for the measurement screen at each measurement's respective rate. Also
    *                       sets the screen up if we just switched to it
    * Author(s): Yasin Alissa
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
        tft.print("Temperature:");
        tft.setCursor(20, 118);
        tft.print("HV Current:");
        tft.setCursor(20, 148);
        tft.print("HV Voltage:");
        tft.setCursor(20, 178);
        tft.print("HVIL Status:");
    }

    tft.setTextColor(BLACK);


    // Update the SOC State Change --- 1 Hz or if we just switched to this screen
    tft.fillRect(150, 43, 90, 30, WHITE);
    tft.setCursor(150, 58);
    tft.print(*sData.charge);

    // Update the Temperature State Change --- 1 Hz or if we just switched to this screen
    tft.fillRect(150, 73, 90, 30, WHITE);
    tft.setCursor(150, 88);
    tft.print(*mData.temperature);


    // Update the Current State Change --- 1/2 Hz or if we just switched to this screen
    if (seconds % 2 == 0 || newScreen) {
        tft.fillRect(150, 103, 90, 30, WHITE);
        tft.setCursor(150, 118);
        tft.print(*mData.hvCurrent);
    }

    // Update the Voltage State Change --- 1/3 Hz or if we just switched to this screen
    if (seconds % 3 == 0 || newScreen) {
        tft.fillRect(150, 133, 90, 30, WHITE);
        tft.setCursor(150, 148);
        tft.print(*mData.hvVoltage);
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
    }


}

void alarmPage(Elegoo_TFTLCD tft, bool newScreen, alarmData aData, int seconds) {
    /****************
    * Function name: alarmPage
    * Function inputs: the TFT screen, an indicator if we just switched to this screen, the alarmData struct,
    *                  and the seconds elapsed since we started running the system
    * Function outputs: none
    * Function description: Updates the display for the alarm screen at each alarm's respective rate. Also sets
    *                       the screen up if we just switched to it
    * Author(s): Yasin Alissa
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

    tft.setTextColor(BLACK);

    // Update the HVIL Alarm Status --- 1 Hz or if we just switched to this screen
    tft.fillRect(95, 43, 145, 30, WHITE);
    tft.setCursor(95, 58);
    tft.print(*aData.hvilAlarmStatus);

    // Update the Overcurrent Alarm Status --- 1/2 Hz or if we just switched to this screen
    if (seconds % 2 == 0 || newScreen) {
        tft.fillRect(95, 73, 145, 30, WHITE);
        tft.setCursor(95, 88);
        tft.print(*aData.overcurrentStatus);
    }

    // Update the HVOOR Alarm Status --- 1/3 Hz or if we just switched to this screen
    if (seconds % 3 == 0 || newScreen) {
        tft.fillRect(95, 103, 145, 30, WHITE);
        tft.setCursor(95, 118);
        tft.print(*aData.hvOutOfRangeStatus);
    }
}

void batteryPage(Elegoo_TFTLCD tft, bool newScreen, contactorData cData) {
    /****************
    * Function name: batteryPage
    * Function inputs: the TFT screen, an indicator if we just switched to this screen, and the contactorData struct
    * Function outputs: none
    * Function description: Updates the display for the battery on/off screen if there is a change needed. Also sets
    *                       the screen up if we just switched to it
    * Author(s): Yasin Alissa
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
    }

}

void displayTask(void* dData) {
    /****************
    * Function name: displayTask
    * Function inputs: void* pointer to the displayData struct
    * Function outputs: none
    * Function description: Updates all the values of each page's statuses at their respective rates
    * Author(s): Yasin Alissa
    *****************/
    displayData* data = (displayData*) dData;
    // If we just started the system, draw the buttons on the screen
    if (*data->seconds == 0) {
        buttons(*data->tft);
    }
    // This tells us if we just switched to this screen
    bool newScreen = (*data->oldPage != *data->currPage);
    // Run this method only if we're currently on the measurement page
    if (*data->currPage == MEASURE_PAGE) {
        measurePage(*data->tft, newScreen, *data->mData, *data->sData, *data->seconds);
    // Run this method only if we're currently on the alarms page
    } else if (*data->currPage == ALARM_PAGE) {
        alarmPage(*data->tft, newScreen, *data->aData, *data->seconds);
    // Run this method only if we're currently on the battery on/off page
    } else if (*data->currPage == BATTERY_PAGE) {
        batteryPage(*data->tft, newScreen, *data->cData);
    }
    // Set the old page to the current page for the next cycle
    *data->oldPage = *data->currPage;
}