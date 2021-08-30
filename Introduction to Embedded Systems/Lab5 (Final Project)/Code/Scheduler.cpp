#include "Scheduler.h"

void insertNode(TCBLinkedList* list, TCB* node) {
    /****************
    * Function name: insertNode
    * Function inputs: pointer to the TCB linked list we're inserting into and the node we're inserting
    * Function outputs: none
    * Function description: Inserts the given node to the end of the given linked list
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    // If head is NULL, set the head and tail pointers to point to this node
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    // Otherwise, head is not NULL, add the node to the end of the list
    } else {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }
}

void deleteNode(TCBLinkedList* list, TCB* node) {
    /****************
    * Function name: deleteNode
    * Function inputs: pointer to the TCB linked list we're deleting from and the node we're deleting
    * Function outputs: none
    * Function description: Deletes the given node from the given linked list
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    // If the head pointer points to NULL, the list is empty and there is nothing to delete
    if (list->head == NULL) {
        return;
    // Otherwise, if the head pointer and tail pointer are equal, there is only one node in the list, set the head and tail to NULL
    } else if (list->head == list->tail && list->head == node) {
        list->head = NULL;
        list->tail = NULL;
    // Otherwise, if the head pointer is equal to the node we want to delete set the head pointer to the next node in the list (head = head -> next)
    } else if (list->head == node) {
        list->head = node->next;
    // Otherwise, if the tail pointer is equal to the node we want to delete, set the tail pointer to the previous node in the list
    } else if (list->tail == node) {
        list->tail = node->prev;
    // Otherwise, we are in the middle of the list update the previous and next pointers of the surrounding nodes
    } else {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    // Set the node's next and previous pointers to NULL
    node->next = NULL;
    node->prev = NULL;
}