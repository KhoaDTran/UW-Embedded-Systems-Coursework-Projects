#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
// Delays the code continuing to run for the given number of seconds.
// Seconds must be greater than or equal to 0
void delay(double seconds);

// Prints the message "A B C D" in the console then pauses for the given
// delay in seconds
void f1Data(double delay1);

// Clears the console then pauses for the given delay in seconds
void f2Clear(double delay2);

// Flashes the message "A B C D" for a number of seconds then clears it for
// another number of seconds. It repeats this behavior indefinitely so the
// program must be manually stopped
int main() {
    // Makes sure the console's buffer prints without a new line needed
    setbuf(stdout, NULL);
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
    while (1) {
        // Print the message then pause for a second
        f1Data(amount);

        // Clear the message then pause for a second
        f2Clear(amount);
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

void f1Data(double delay1) {
    // Sets the message we want to flash
    char* message = "A B C D";
    // Print the message then delays for the given number of seconds
    printf("%s", message);
    delay((double) delay1);
}

void f2Clear(double delay2) {
    char* clear = "\b\b\b\b\b\b\b";
    // Print the message then delays for the given number of seconds
    printf("%s", clear);
    delay((double) delay2);
}
