// Khoa Tran
// CSE 374 HW 5
// 05/11/2020

// Purpose of makeNode.c:
// Implements a function to create an instance of a node
// by allocating enough memory and initializing its fields

#include "makeNode.h"
#include <stdlib.h>
#include <stdio.h>

// Implements a trie node with the default field
// of child being reference to 8 other pointers to a node
Node * makeNode() {
  void * temp = (Node *) malloc(sizeof(Node));
  if (!temp) {
    fprintf(stderr, "Failed to allocate memory. Closing program.");
    exit(EXIT_FAILURE);
  }
  Node * ptrNode = temp;
  ptrNode->next = NULL;
  ptrNode->word = NULL;
  ptrNode->child = (Node **) malloc(NUM_CHILD * sizeof(Node *));
  for (int i = 0; i < NUM_CHILD; i++) {
    ptrNode->child[i] = NULL;
  }
  return ptrNode;
}
