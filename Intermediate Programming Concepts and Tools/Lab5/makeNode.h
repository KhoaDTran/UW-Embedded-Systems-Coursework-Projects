// Khoa Tran
// CSE 374 HW 5
// 05/11/2020

// Purpose of makeNode.h:
// Interface for a struct Node and function to create one

#ifndef NODE_HFILE
#define NODE_HFILE
#define NUM_CHILD 8

// Creates a single struct node that has pointers to a word,
// the next node, and its child
typedef struct typeNode {
  char * word;
  struct typeNode* next;
  struct typeNode** child;
} Node;

// Creates an instance of a node with default fields:
// word, next, child[] to be NULL
Node * makeNode();

#endif
