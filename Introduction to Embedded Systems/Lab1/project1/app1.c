#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Delays the code continuing to run for 1 second
void delay();

// Flashes the message "A B C D" for 1 second then clears it for 1 second. It
// repeats this behavior indefinitely so the program must be manually stopped
int main() {

    // Sets the message we want to flash
    char* message = "A B C D";
    // Sets the string used to clear the message
    char* clear = "\b\b\b\b\b\b\b";
    // Makes sure the console's buffer prints without a new line needed
    setbuf(stdout, NULL);
    // Loop indefinitely
    while (1) {
        // Print the message then pause for a second
        printf("%s", message);
        delay();
        // Clear the message then pause for a second
        printf("%s", clear);
        delay();
    }

    return EXIT_SUCCESS;
}

void delay() {
    time_t startTime, currTime = 0;
    // Get the time we started at and set the current time to the same time
    time(&startTime);
    currTime = startTime;
    // Loop until the difference in the current time and the start time is
    // at least 1 second
    while (difftime(currTime, startTime) < 1.0) {
        // Get the new current time
        time(&currTime);
    }
}