// Written by Porter Jones (pbjones@cs.washington.edu)
//
// This is a file for managing a store of various aisles,
// represented by an array of 64-bit integers

#include <stddef.h>  // To be able to use NULL
#include "aisle_manager.h"
#include "store_client.h"
#include "store_util.h"

// Number of aisles in the store
#define NUM_AISLES 10

// Number of sections per aisle
#define SECTIONS_PER_AISLE 4

// Number of items in the stockroom (2^6 different id combinations)
#define NUM_ITEMS 64

// Global array of aisles in this store. Each unsigned long in the array
// represents one aisle.
unsigned long aisles[NUM_AISLES];

// Array used to stock items that can be used for later. The index of the array
// corresponds to the item id and the value at an index indicates how many of
// that particular item are in the stockroom.
int stockroom[NUM_ITEMS];


/* Starting from the first aisle, refill as many sections as possible using
 * items from the stockroom. A section can only be filled with items that match
 * the section's item id. Priotizes and fills sections with lower addresses
 * first. Sections with lower addresses should be fully filled (if possible)
 * before moving onto the next section.
 */
void refill_from_stockroom() {
  // TODO: implement this function
  int i;
  int index;
  unsigned long* aisle;
  unsigned short id;
  int val;
  unsigned short itemsInSection;
  unsigned short difference;
  int update;
  for (i = 0; i<10; i++) {
    aisle = &(aisles[i]);
    for (index = 0; index < 4; index++) {
      id = get_id(aisle, index);
      itemsInSection = num_items(aisle, index);
      val = stockroom[id];
      difference = 10 - itemsInSection;
      if (val > 0) {
	if (val >= difference) {
	  update = val - difference;
	  add_items(aisle, index, difference);
	  stockroom[id] = update;
	} else {
	  add_items(aisle, index, val);
	  stockroom[id] = 0;
	}
      }
    }
  }
}

/* Remove at most num items from sections with the given item id, starting with
 * sections with lower addresses, and return the total number of items removed.
 * Multiple sections can store items of the same item id. If there are not
 * enough items with the given item id in the aisles, first remove all the
 * items from the aisles possible and then use items in the stockroom of the
 * given item id to finish fulfilling an order. If the stockroom runs out of
 * items, you should remove as many items as possible.
 */
int fulfill_order(unsigned short id, int num) {
  // TODO: implement this function
  int i;
  int index;
  int result;
  int stockVal;
  int difference;
  unsigned short idVal;
  unsigned short numItems;
  unsigned long* aisle;
  result = 0;
  for (i = 0; i<10; i++) {
    aisle = &(aisles[i]);
    for (index = 0; index < 4; index++) {
      idVal = get_id(aisle, index);
      if (id == idVal) {
	numItems = num_items(aisle, index);
	if (num > numItems) {
	  num = num - numItems;
	  remove_items(aisle, index, numItems);
	  result = result + numItems;
	} else {
	  remove_items(aisle, index, num);
	  result = result + num;
	  num = 0;
	}
      }
    }
  }
  if (num > 0) {
    stockVal = stockroom[id];
    if (stockVal >= num) {
      difference = stockVal - num;
      stockroom[id] = difference;
      result = result + num;
      num = 0;
    } else {
      stockroom[id] = 0;
      result = result + stockVal;
    }
  }
  return result; 
}

/* Return a pointer to the first section in the aisles with the given item id
 * that has no items in it or NULL if no such section exists. Only consider
 * items stored in sections in the aisles (i.e., ignore anything in the
 * stockroom). Break ties by returning the section with the lowest address.
 */
unsigned short* empty_section_with_id(unsigned short id) {
  // TODO: implement this function
  int i;
  int index;
  unsigned short* result;
  unsigned short idVal;
  unsigned short numItems;
  unsigned long* aisle;
  for (i = 0; i<10; i++) {
    aisle = &(aisles[i]);
    for (index = 0; index < 4; index++) {
      idVal = get_id(aisle, index);
      if (idVal == id) {
	numItems = num_items(aisle, index);
	if (numItems == 0)  {
	  result = (unsigned short*)(aisle) + index;
	  return result;
	} 
      }
    }
  }	  
  return NULL;
}

/* Return a pointer to the section with the most items in the store. Only
 * consider items stored in sections in the aisles (i.e., ignore anything in
 * the stockroom). Break ties by returning the section with the lowest address.
 */
unsigned short* section_with_most_items() {
  // TODO: implement this function
  int i;
  int index;
  unsigned short* result;
  unsigned short numItems;
  unsigned long* aisle;
  unsigned short max;
  max = 0;
  i = 9;
  for (i = 9; i >= 0; i--) {
    aisle = &(aisles[i]);
    for (index = 3; index >= 0; index--) {
      numItems = num_items(aisle, index);
      if (numItems >= max) {
	max = numItems;
	result = (unsigned short*)(aisle) + index;
      }
    }
  }
  return result;
}      
