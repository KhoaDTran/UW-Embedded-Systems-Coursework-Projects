// Khoa Tran
// 05/03/2020
// Homework 4: Gasp.c
// Purpose: Create a program that takes an input of a string and text files
// and output any lines that has the corresponding string input.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define INPUT_LIMIT 500
#define STRING_LIMIT 100

// given_file = the array of characters of the given file
// matching_str = the array of characters of the given string input
// case_ignore = boolean checker to ignore casing or not
// line_number = boolean checker to include the line numbers or not
// With the given file, string, and any possible options included,
//  find any lines in the text file that matches the given string,
//  including the option of ignoring case or including line numbers.
int find_match(char *given_file, char *matching_str,
               int case_ignore, int line_number);

// argc = number of arguments provided
// argv = array of arguments
// With the given arguments, set the program to the options provided,
// as well as the strings and file given.
// Print out matching statements at the end.
int main(int argc, char *argv[]) {
  int num_options;
  int case_ignore;
  int line_number;
  char *matching_str = NULL;
  for (int i = 1; i < argc; i++) {
    if (strncmp(argv[i], "-i", 2) == 0) {
      num_options++;
      case_ignore = 1;
    } else if (strncmp(argv[i], "-n", 2) == 0) {
      num_options++;
      line_number = 1;
    } else if (matching_str == NULL) {
      if (strlen(argv[i]) > STRING_LIMIT) {
        return EXIT_FAILURE;
      } else {
        matching_str = argv[i];
      }
    } else {
      find_match(argv[i], matching_str, case_ignore, line_number);
    }
  }
  if (argc - num_options < 3) {
    fprintf(stderr, "Usage: -i -n <string to compare> <file to open>\n");
    return EXIT_FAILURE;
  }
return EXIT_SUCCESS;
}

// given_file = the array of characters of the given file
// matching_str = the array of characters of the given string input
// case_ignore = boolean checker to ignore casing or not
// line_number = boolean checker to include the line numbers or not
// With the given file, string, and any possible options included,
// find any lines in the text file that matches the given string,
// including the option of ignoring case or including line numbers.
int find_match(char *given_file, char *matching_str,
               int case_ignore, int line_number) {
  char *str = matching_str;
  char temp[INPUT_LIMIT];
  char match[INPUT_LIMIT];
  int number_line = 1;
  FILE *file_open = fopen(given_file, "r");
  if (file_open) {
    for (int i = 0; i < strlen(str); i++) {
      str[i] = tolower(str[i]);
    }
    while (fgets(temp, INPUT_LIMIT, file_open) != NULL) {
      strcpy(match, temp);
      if (case_ignore  == 1) {
        for (int i = 0; i < strlen(temp); i++) {
          temp[i] = tolower(temp[i]);
        }
      }
      if ((strstr(temp, str)) != NULL) {
        if (line_number == 1) {
          printf("Line %d: %s:%s\n", number_line, given_file, match);
        } else {
          printf("%s:%s\n", given_file, match);
        }
      }
      number_line++;
    }
    fclose(file_open);
  } else {
    fprintf(stderr, "Input file not valid\n");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
