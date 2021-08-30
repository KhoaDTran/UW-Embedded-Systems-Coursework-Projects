#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "app6_func.h"

// Flashes the message "A B C D" for a number of seconds then clears it for
// another number of seconds. It repeats this behavior indefinitely so the
// program must be manually stopped
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
        // Print the message then pause for the message delay
        displayAndDelay(message, &amount);
        // Clear the message then pause for the clear delay
        displayAndDelay(clear, &amount);
    }

    return EXIT_SUCCESS;
}
