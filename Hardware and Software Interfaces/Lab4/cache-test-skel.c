/*
Name: Khoa Tran
UWNetID: ktdt01
CSE 351 Lab 4, Part 1 - Mystery Caches
*/

#include <stdlib.h>
#include <stdio.h>

#include "support/mystery-cache.h"

/*
 * NOTES: 
 * 1. When using access_cache() you do not need to provide a "real" memory
 * addresses. You can use any convenient integer value as a memory address,
 * you should not be able to cause a segmentation fault by providing a memory
 * address out of your programs address space as the argument to access_cache.
 * 
 * 2. Do NOT change the provided main function, especially the print statement.
 * If you do so, the autograder may fail to grade your code even if it produces
 * the correct result.
 */

/*
   Returns the size (in B) of each block in the cache.
*/
int get_block_size(void) {
  /* YOUR CODE GOES HERE */
  flush_cache();
  access_cache(0);
  int result = 0;
  while(access_cache(result)) {
    result = result + 1;
  }
  return result;
}

/*
   Returns the size (in B) of the cache.
*/
int get_cache_size(int block_size) {
  /* YOUR CODE GOES HERE */
  flush_cache();
  access_cache(0);
  int result = 0;
  while(access_cache(0)) {
    flush_cache();
    result = result + 1;
    for (int i = 0; i <block_size*result; i+=block_size) {
      access_cache(i);
    }
  }
  return (result-1)*block_size;
}

/*
   Returns the associativity of the cache.
*/
int get_cache_assoc(int cache_size) {
  /* YOUR CODE GOES HERE */
  flush_cache();
  access_cache(0);
  int result = 0;
  int i;
  while(access_cache(0)) {
    result++;
    flush_cache();
    for (i = 0; i <= result; i++) {
      access_cache(i * cache_size);
    }
  }
  return result;
}

int main(void) {
  int size;
  int assoc;
  int block_size;

  cache_init(0, 0);

  block_size = get_block_size();
  size = get_cache_size(block_size);
  assoc = get_cache_assoc(size);

  printf("Cache block size: %d bytes\n", block_size);
  printf("Cache size: %d bytes\n", size);
  printf("Cache associativity: %d\n", assoc);

  return EXIT_SUCCESS;
}
