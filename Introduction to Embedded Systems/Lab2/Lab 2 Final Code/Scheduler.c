#include "Scheduler.h"

void scheduler(TCB* queue[], int size) {
    /****************
    * Function name: scheduler
    * Function inputs: a queue of TCBs and the size of the queue
    * Function outputs: none
    * Function description: Schedules each TCB's task to run once per second
    * Author(s): Yasin Alissa
    *****************/
    // Get the time we started at
    unsigned long timeStarted = millis();
    // Perform each TCB's task with its data
    for (int i = 0; i < size; i++) {
        TCB currTCB = *queue[i];
        currTCB.task(currTCB.taskDataPtr);
    }
    // Delay so that we end 1 second after we started
    delay(1000 - (millis() - timeStarted));
}
