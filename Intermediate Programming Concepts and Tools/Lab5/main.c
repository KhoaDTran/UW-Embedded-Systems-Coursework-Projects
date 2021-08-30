// Khoa Tran
// CSE 374 HW 5
// 05/11/2020

// Purpose of main.c:
// From words in a dictionary, match each word into
// a numbered key sequence with letters representing
// numbers from 2-9 and storing this data in a trie
// data structure in order to preserve memory and
// maintain common prefixes. Also, ask the user for
// number sequence inputs, search through the trie,
// and print out the associated word with the potential
// of printing all the words

#include "makeTrie.h"

// Takes in one file as an argument. Use file as
// a dictionary, building and inserting each word
// into the trie. Prompting the user for a number
// sequence to print the associated word
// until exit is entered.
int main(int argc, char * argv[]) {
  if (argc == 1) {
    fprintf(stderr, "File argument missing.");
    return EXIT_FAILURE;
  }
  FILE *f = fopen(argv[1], "r");
  if (!f) {
    fprintf(stderr, "File doesn't exit.");
    return EXIT_FAILURE;
  }
  Node *overallRoot = buildTrie(f);
  fclose(f);
  void * temp = (char *) malloc(MAXIMUM_WORD_LENGTH);
  if (!temp) {
    fprintf(stderr, "Failed to allocate memory. Closing program.");
    return EXIT_FAILURE;
  }
  char *wordInput = temp;
  Node *nodeWord = NULL;
  printf("Enter \"exit\" to quit.\n");
  printf("Enter Key Sequence (or \"#\" for next word):\n");
  while (fgets(wordInput, MAXIMUM_WORD_LENGTH, stdin) &&
         strncmp("exit\n", wordInput, strlen(wordInput))) {
    if (isdigit(wordInput[0])) {
      nodeWord = searchDict(wordInput, overallRoot);
    }
    char * poundCheck = strstr(wordInput, "#");
    while (nodeWord && poundCheck && *poundCheck == '#') {
      nodeWord = nodeWord->next;
      poundCheck++;
    }
    if (!nodeWord) {
        printf("Number sequence doesn't have a "
               "word assocaited or any left\n");
    }
    if (nodeWord && nodeWord->word) {
      printf("'%s'\n", nodeWord->word);
    } else {
      printf("There are no more T9onyms for this particular number\n");
    }
    printf("Enter Key Sequence (or \"#\" for next word):\n");
  }
  totalFree(overallRoot);
  free(wordInput);
  return 0;
}
