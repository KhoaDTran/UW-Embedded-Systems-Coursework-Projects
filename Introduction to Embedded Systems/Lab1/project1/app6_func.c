#include <stdio.h>
#include <time.h>
#include "app6_func.h"

void delay(double seconds) {
    time_t startTime, currTime = 0;
    // Get the time we started at and set the current time to the same time
    time(&startTime);
    currTime = startTime;
    // Loop until the difference in the current time and the start time is
    // at least the given number of seconds
    while (difftime(currTime, startTime) < seconds) {
        // Get the new current time
        time(&currTime);
    }
}

void displayAndDelay(char* message, double* toDelay) {
    // Print the message then delays for the given number of seconds
    printf("%s", message);
    delay((double) *toDelay);
}
