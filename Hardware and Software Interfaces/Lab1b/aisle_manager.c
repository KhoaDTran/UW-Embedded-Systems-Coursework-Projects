// ----------------------------------------------------------------------------
// Overview
// ----------------------------------------------------------------------------
//  This is a program to keep track of the items in a small aisle of a store.
//
//  A store's aisle is represented by a 64-bit long integer, which is broken
//  into 4 16-bit sections representing one type of item each. Note that since
//  a section is 16-bits, it fits nicely into C's short datatype.
//
//  Aisle Layout:
//
//    Within an aisle, sections are indexed starting with the least-significant
//    section being at index 0 and continuing up until one less than the number
//    of sections.
//
//    Example aisle:
//
//                MSB                                                       LSB
//                  +-------------+-------------+-------------+-------------+
//                  |  Section 3  |  Section 2  |  Section 1  |  Section 0  |
//                  +-------------+-------------+-------------+-------------+
//                  |             |             |             |             |
//      bit offset: 64            48            32            16            0
//
//  Section Layout:
//
//    A section in an aisle is broken into 2 parts. The 6 most significant bits
//    represent a unique identifier for the type of item stored in that
//    section. The rest of the bits in a section (10 least significant)
//    indicate individual spaces for items in that section. For each of the 10
//    bits/spaces, a 1 indicates that an item of the section's type is stored
//    there and a 0 indicates that the space is empty.
//
//    Example aisle section: 0x651A
//
//                MSB                               LSB
//                  +-----------+-------------------+
//                  |0 1 1 0 0 1|0 1 0 0 0 1 1 0 1 0|
//                  +-----------+-------------------+
//                  | item id   | section spaces    |
//      bit offset: 16          10                  0
//
//      In this example, the item id is 0b011001, and there are currently 4
//      items stored in the section (at bit offsets 8, 4, 3, and 1) and 6
//      vacant spaces.
//
//  Written by Porter Jones (pbjones@cs.washington.edu)
// ----------------------------------------------------------------------------

#include "aisle_manager.h"
#include "store_util.h"

// the number of total bits in a section
#define SECTION_SIZE 16

// The number of bits in a section used for the item spaces
#define NUM_SPACES 10

// The number of bits in a section used for the item id
#define ID_SIZE 6

// The number of sections in an aisle
#define NUM_SECTIONS 4

// TODO: Fill in these with the correct hex values

// Mask for extracting a section from the least significant bits of an aisle.
// (aisle & SECTION_MASK) should preserve a section's worth of bits at the
// lower end of the aisle and set all other bits to 0. This is essentially
// extracting section 0 from the example aisle shown above.
#define SECTION_MASK 0xFFFF

// Mask for extracting the spaces bits from a section.
// (section & SPACES_MASK) should preserve all the spaces bits in a section and
// set all non-spaces bits to 0.
#define SPACES_MASK 0x03FF

// Mask for extracting the ID bits from a section.
// (section & ID_MASK) should preserve all the id bits in a section and set all
// non-id bits to 0.
#define ID_MASK 0xFC00


/* Given a pointer to an aisle and a section index, return the section at the
 * given index of the given aisle.
 *
 * Can assume the index is a valid index (0-3 inclusive).
 */
unsigned short get_section(unsigned long* aisle, int index) {
  // TODO: implement this method
  unsigned short result = (*aisle>>(index*16)) & SECTION_MASK;
  return result;
}

/* Given a pointer to an aisle and a section index, return the spaces of the
 * section at the given index of the given aisle. The returned short should
 * have the least 10 significant bits set to the spaces and the 6 most
 * significant bits set to 0.
 *
 * Can assume the index is a valid index (0-3 inclusive).
 */
unsigned short get_spaces(unsigned long* aisle, int index) {
  // TODO: implement this method
  unsigned short section = get_section(aisle, index);
  unsigned result = section & SPACES_MASK;
  return result;
}

/* Given a pointer to an aisle and a section index, return the id of the
 * section at the given index of the given aisle. The returned short should
 * have the least 6 significant bits set to the id and the 10 most significant
 * bits set to 0.
 *
 * Example: if the section is 0b0110010100011010, return 0b0000000000011001.
 *
 * Can assume the index is a valid index (0-3 inclusive).
 */
unsigned short get_id(unsigned long* aisle, int index) {
  // TODO: implement this method
  unsigned short section = get_section(aisle, index);
  unsigned short result = (section & ID_MASK) >> 10;
  return result;
}

/* Given a pointer to an aisle, a section index, and a short representing a new
 * bit pattern to be used for section, set the section at the given index of
 * the given aisle to the new bit pattern.
 *
 * Can assume the index is a valid index (0-3 inclusive).
 */
void set_section(unsigned long* aisle, int index, unsigned short new_section) {
  // TODO: implement this method
  unsigned long temp;
  if (index  == 3) {
    temp = 0x0000FFFFFFFFFFFF;
  } else if (index == 2) {
    temp = 0xFFFF0000FFFFFFFF;
  } else if (index == 1) {
    temp = 0xFFFFFFFF0000FFFF;
  } else {
    temp = 0xFFFFFFFFFFFF0000;
  }
  *aisle = (*aisle & temp) | (new_section << index*16);
}

/* Given a pointer to an aisle, a section index, and a short representing a new
 * bit pattern to be used for the spaces of the section, set the spaces for the
 * section at the given index of the given aisle to the new bit pattern. The
 * new spaces pattern should be in the 10 least significant bits of the given
 * bit pattern. If the new pattern uses bits outside the 10 least significant
 * bits, then the method should leave the spaces unchanged.
 *
 * Can assume the index is a valid index (0-3 inclusive).
 */
void set_spaces(unsigned long* aisle, int index, unsigned short new_spaces) {
  // TODO: implement this method
  unsigned short section = get_section(aisle, index);
  unsigned short newSection;
  if (new_spaces < 1024) {
    newSection = ((section & ID_MASK) | new_spaces);
  } else {
    newSection = section;
  }
  set_section(aisle, index, newSection);
}

/* Given a pointer to an aisle, a section index, and a short representing a new
 * bit pattern to be used for the id of the section, set the id for the section
 * at the given index of the given aisle to the new bit pattern. The new id
 * pattern should be in the 6 least significant bits of the given bit pattern.
 * If the new pattern uses bits outside the 6 least significant bits, then the
 * method should leave the id unchanged.
 *
 * Can assume the index is a valid index (0-3 inclusive).
 */
void set_id(unsigned long* aisle, int index, unsigned short new_id) {
  // TODO: implement this method
  unsigned short section = get_section(aisle, index);
  unsigned short newSection;
  if (new_id < 64) {
    newSection = ((section & SPACES_MASK) | new_id << 10);
  } else {
    newSection = section;
  }
  set_section(aisle, index, newSection);
}

/* Given a pointer to an aisle, a section index, and a space index, toggle the
 * item in the given space index of the section at the given section index in
 * the given aisle. Toggling means that if the space was previously empty, it
 * should now be filled with an item, vice-versa.
 *
 * Can assume the section index is a valid index (0-3 inclusive).
 * Can assume the spaces index is a valid index (0-9 inclusive).
 */
void toggle_space(unsigned long* aisle, int index, int space_index) {
  // TODO: implement this method
  unsigned short section = get_section(aisle, index);
  unsigned short newSection = section ^ 1 << space_index;
  set_section(aisle, index, newSection);
}

/* Given a pointer to an aisle and a section index, return the number of items
 * in the section at the given index of the given aisle.
 *
 * Can assume the index is a valid index (0-3 inclusive).
 */
unsigned short num_items(unsigned long* aisle, int index) {
  // TODO: implement this method
  unsigned short spaces = get_spaces(aisle, index);
  unsigned short result = 0;
  while(spaces > 0) {
    if (spaces & 1) {
      result++;
    }
    spaces = spaces >> 1;
  }
  return result;
}

/* Given a pointer to an aisle, a section index, and the desired number of
 * items to add, add at most the given number of items to the section at the
 * given index in the given aisle. Items should be added to the least
 * significant spaces possible. If n is larger than or equal to the number of
 * empty spaces in the section, then the section should appear full after the
 * method finishes.
 *
 * Can assume the index is a valid index (0-3 inclusive).
 */
void add_items(unsigned long* aisle, int index, int n) {
  // TODO: implement this method
  unsigned short numItems = num_items(aisle, index);
  unsigned short emptySpaces = 10 - numItems;
  unsigned short spaces = get_spaces(aisle, index);
  unsigned short i;  
  if (numItems + n > 10) {
    emptySpaces = emptySpaces;
  } else {
    emptySpaces = n;
  }
  if (n != 0) {
    for (i = 0; i <= 9; i++){
      if (!(spaces & (1 << i)) && (emptySpaces > 0)) {
	  toggle_space(aisle, index, i);
	  emptySpaces = emptySpaces - 1;
      }
    }
  }
} 
/* Given a pointer to an aisle, a section index, and the desired number of
 * items to remove, remove at most the given number of items from the section
 * at the given index in the given aisle. Items should be removed from the
 * least significant spaces possible. If n is larger than or equal to the
 * number of items in the section, then the section should appear empty after
 * the method finishes.
 *
 * Can assume the index is a valid index (0-3 inclusive).
 */
void remove_items(unsigned long* aisle, int index, int n) {
  // TODO: implement this method
  unsigned short numItems = num_items(aisle, index);
  unsigned short numItemsNeedClear;
  unsigned short spaces = get_spaces(aisle, index);
  unsigned short section;
  unsigned short newSection;
  int i;
  if (n >= numItems) {
    numItemsNeedClear = numItems;
  } else {
    numItemsNeedClear = n;
  }
  if (n != 0) {
    for (i = 0; i <= 9; i++) {
      if ((spaces & (1 << i) && (numItemsNeedClear > 0))) {
	section = get_section(aisle, index);
	newSection = (section & (~(1 << i)));
	set_section(aisle, index, newSection);
	numItemsNeedClear = numItemsNeedClear - 1;
      }
    }
  }
}

/* Given a pointer to an aisle, a section index, and a number of slots to
 * rotate by, rotate the items in the section at the given index of the given
 * aisle to the left by the given number of slots.
 *
 * Example: if the spaces are 0b0111100001, then rotating left by 2 results
 *          in the spaces     0b1110000101
 *
 * Can assume the index is a valid index (0-3 inclusive).
 * Can NOT assume n < NUM_SPACES (hint: find an equivalent rotation).
 */
void rotate_items_left(unsigned long* aisle, int index, int n) {
  // TODO: implement this method
  if (n > NUM_SPACES) {
    n = n % NUM_SPACES;
  }
  unsigned short spaces = get_spaces(aisle, index);
  unsigned short newSpaces = ((spaces << n) | (spaces >> (10 - n))) & SPACES_MASK;  
  set_spaces(aisle, index, newSpaces);
}

/* Given a pointer to an aisle, a section index, and a number of slots to
 * rotate by, rotate the items in the section at the given index of the given
 * aisle to the right by the given number of slots.
 *
 * Example: if the spaces are 0b1000011110, then rotating right by 2 results
 *          in the spaces     0b1010000111
 *
 * Can assume the index is a valid index (0-3 inclusive).
 * Can NOT assume n < NUM_SPACES (hint: find an equivalent rotation).
 */
void rotate_items_right(unsigned long* aisle, int index, int n) {
  // TODO: implement this method
  if (n > NUM_SPACES) {
    n = n % NUM_SPACES;
  }
  unsigned short spaces = get_spaces(aisle, index);
  unsigned short newSpaces = ((spaces >> n) | (spaces << (10 - n))) & SPACES_MASK;
  set_spaces(aisle, index, newSpaces);
}
