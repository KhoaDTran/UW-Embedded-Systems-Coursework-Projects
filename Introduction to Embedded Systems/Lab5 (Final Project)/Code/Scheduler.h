#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "Arduino.h"
#include "TaskControlBlock.h"

typedef struct tcbLinkedList {
    TCB* head;
    TCB* tail;
} TCBLinkedList;

void insertNode(TCBLinkedList* list, TCB* node);

void deleteNode(TCBLinkedList* list, TCB* node);

#endif