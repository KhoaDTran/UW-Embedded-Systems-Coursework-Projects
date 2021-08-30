#ifndef _TASKCONTROLBLOCK_H
#define _TASKCONTROLBLOCK_H


// This struct represents a task control block (TCB)  
// TCB encapsulates task function and data
typedef struct taskControlBlock {
  void (*task)(void*);
  void* taskDataPtr;
  struct taskControlBlock* next;
  struct taskControlBlock* prev;
  const int* period;
  int* timeRemain;
} TCB;

#endif  // _TASKCONTROLBLOCK_H
