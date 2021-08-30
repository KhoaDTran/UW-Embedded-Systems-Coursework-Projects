#include "Scheduler.h"

void scheduler(TCB* list) {
    /****************
    * Function name: scheduler
    * Function inputs: a linked list of TCBs
    * Function outputs: none
    * Function description: Schedules each TCB's task to run in order
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    // Get the head of the linked list as the current TCB
    TCB* currTCB = list;
    // Keeps going until the the TCB we're at is null
    while (currTCB != NULL) {
        // Perform the current TCB's task
        currTCB->task(currTCB->taskDataPtr);
        // Point to the next TCB
        currTCB = currTCB->next;
    }
}