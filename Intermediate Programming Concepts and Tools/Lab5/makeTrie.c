// Khoa Tran
// CSE 374 HW 5
// 05/11/2020

// Purpose of makeTrie.c:
// Builds the trie data structure with the given
// text file by associating each letter to a number
// and inserting into the trie from the number index
// resulting in each node having 8 children.
// Can search through the trie for possible words
// of a given number sequence.
#include "makeTrie.h"

// Returns the number index, 0-7, from the given
// letter representing numbers 2-9 to the user.
int getChildren(char letter) {
  int map[ALPHABET] = {
    2, 2, 2,
    3, 3, 3,
    4, 4, 4,
    5, 5, 5,
    6, 6, 6,
    7, 7, 7, 7,
    8, 8, 8,
    9, 9, 9, 9
  };
  int index = letter - 'a';
  return map[index] - 2;
}

// Insert given word into the trie starting from
// the first letter as the overallRoot. Adds onto
// existing path and doesn't modify any path of prefixes.
void insert(Node *overallRoot, char *word) {
  Node *root = overallRoot;
  int index = 0;
  while (*(word + index)) {
    char letter = word[index];
    int childrenIndex = getChildren(letter);
    Node * childrenNode = root->child[childrenIndex];
    if (!childrenNode) {
      childrenNode = makeNode();
      root->child[childrenIndex] = childrenNode;
    }
    index++;
    root = childrenNode;
  }
  int wordlen = index + 1;
  if (root->word) {
    Node * current = root;
    while (current->next && current) {
      current = current->next;
    }
    Node * new = makeNode();
    root = new;
    current->next = new;
  }
  void * ptr  = (char *) malloc(wordlen);
  if (!ptr) {
    fprintf(stderr, "Failed to allocate memory. Closing program.");
    exit(EXIT_FAILURE);
  }
  root->word = ptr;
  strncpy(root->word, word, wordlen);
}

// Builds trie nodes with the given file
// by going through each word and inserting into the trie.
Node * buildTrie(FILE *f) {
  Node * overallRoot;
  void * temp = (char *) malloc(MAXIMUM_WORD_LENGTH);
  if (!temp) {
    fprintf(stderr, "Failed to allocate memory. Closing program.");
    exit(EXIT_FAILURE);
  }
  char * word = temp;
  overallRoot = makeNode();
  while (fgets(word, MAXIMUM_WORD_LENGTH, f)) {
    int length = strlen(word);
    if (word[length - 1] == '\n') {
      word[length - 1] = '\0';
    }
    insert(overallRoot, word);
  }
  free(word);
  return overallRoot;
}

// For the given number sequence,
// associated starting node containing the word
Node * searchDict(char *key, Node *overallRoot) {
  int height = 0;
  Node * root = overallRoot;
  int keyLen = strlen(key) - 1;
  while (root && height < keyLen && key[height] != '#') {
    int index = key[height] - '0' - 2;
    if (index < 0 || !isdigit(key[height])) {
      return NULL;
    }
    height++;
    root = root->child[index];
  }
  return root;
}

// Given a pointer to a node,
// free the node's word and child
void freeNode(Node *node) {
  free(node->word);
  free(node->child);
  free(node);
}

// Given the starting front node,
// free the list of following nodes
void freeList(Node * frontNode) {
  while (frontNode) {
    Node * next = frontNode->next;
    freeNode(frontNode);
    frontNode = next;
  }
}

// Given the node,
// free the node and all of its children
void totalFree(Node * overallRoot) {
  if (overallRoot) {
    for (int i = 0; i < NUM_CHILD; i++) {
      totalFree(overallRoot->child[i]);
    }
    freeList(overallRoot->next);
    freeNode(overallRoot);
  }
}


