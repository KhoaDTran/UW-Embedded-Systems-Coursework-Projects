#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Delays the code continuing to run for the given number of seconds.
// Seconds must be greater than or equal to 0
void delay(double seconds);

// Flashes the message "A B C D" for a number of seconds then clears it for
// another number of seconds.
// The number of seconds is taken from the user input.
// It repeats this behavior indefinitely until the
// program is manually stopped
int main() {
    // Makes sure the console's buffer prints without a new line needed
    setbuf(stdout, NULL);
    // Sets the message to A B C D to flash
    char* message = "A B C D";
    double amount = 0;
    // Ask user for desired seconds of flashing
    printf("How many seconds would you like the message to flash?  ");
    // Only continue when we have valid input
    while (amount == 0) {
        // Scan for user input
        char input[20] = "";
        scanf("%s", input);
        // Convert input to a double
        amount = strtod(input, NULL);
        // If input is invalid, inform the user
        if (amount == 0.0) {
            printf("Invalid input. Try again: ");
        }
    }
    // Sets the string used to clear the message
    char* clear = "\b\b\b\b\b\b\b";
    // Loop indefinitely
    while (1) {
        // Print the message then pause for a second
        printf("%s", message);
        // Delay the given user amount
        delay(amount);
        // Clear the message then pause for a second
        printf("%s", clear);
        // Delay the given user amount
        delay(amount);
    }

    return EXIT_SUCCESS;
}

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
