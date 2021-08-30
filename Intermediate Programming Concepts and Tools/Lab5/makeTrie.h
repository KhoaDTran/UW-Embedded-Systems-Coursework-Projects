// Khoa Tran
// CSE 374 HW 5
// 05/11/2020

// Purpose of makeTrie.h:
// Interface of the trie data structure,
// where each node has 8 children corresponding to 2-9

#ifndef TRIE_HFILE
#define TRIE_HFILE

#include "makeNode.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#define ALPHABET 26
#define MAXIMUM_WORD_LENGTH 14 //Determined after wc -L on the dictionary files

// Ignores 0 and 1 and returns the number index, 0-7,
// that corresponds to the given letter
int getChildren(char letter);

// Insert the given word into the trie nodes
// with the given number index
void insert(Node * overallRoot, char * word);

// Builds the trie nodes with the given words in the
// given file
Node * buildTrie(FILE *f);

// For the given numbers, search through the trie,
// and returns the node associated with the given numbers
// from the dictionary file
Node * searchDict(char * key, Node * overallRoot);

// Frees a given node pointer
void freeNode(Node * node);

// From the front node, free the list of nodes following
void freeList(Node * frontNode);

// Frees the given node and all connected childs
void totalFree(Node * overallRoot);

#endif
