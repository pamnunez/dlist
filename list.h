#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

// A linked list node that holds an integer.
typedef struct Node {
    int value;
    struct Node *next;
} Node;

// A doubly linked list node that holds an integer.
// Challenge: use this in the defn of IntList instead of Node!
typedef struct DNode {
    int value;
    struct DNode *prev;
    struct DNode *next;
} DNode;

// A linked list that contains integers.
typedef struct IntList {
    DNode *first;
} IntList;

///// Part 1: Basic List Operations {{{ ////////////////////////////////////////

// Creates a new, empty IntList.
IntList* mk_list(void);

// Frees the given IntList.
void free_list(IntList *list);

// Prints the given list to the console in the following format:
//
// [1, 2, 3, 4, 5]
//
// The empty list is displayed as follows:
//
// []
//
// print_list inserts a newline after the list.
void print_list(IntList *list);

// Returns true iff the list is empty.
bool is_empty(IntList *list);

// Returns the length of the list.
int length(IntList *list);

// Returns the sum of the values in the given list.
int sum(IntList *list);

// Loads ret with the index of the first occurrence of value in the list.
// Returns true if the operation is successful and false otherwise.
bool index_of(IntList *list, int value, int *ret);

// Inserts the given value into the end of the list.
void push_back(IntList *list, int value);

// Pushes the given value onto the front of the list.
void push_front(IntList *list, int value);

// Inserts the given value into the nth position in the list.  Elements from
// nth index on are shifted to the right to make room.  Returns true if the
// operation is successful and false otherwise (e.g., the nth index is in the
// range 0 <= n <= len(l).
bool insert(IntList *list, int value, int n);

// Inserts the given integer between each pair of integers in the given list.
// For example, interspersing 9 between the following lists yields:
//
// [0, 1, 2]          ~> [0, 9, 1, 9, 2]
// [0, 1, 2, 3, 4, 5] ~> [0, 9, 1, 9, 2, 9, 3, 9, 4, 9, 5]
// [1]                ~> [1]
// []                 ~> []
//
// Note the cases for the list of one element and the empty list!
void intersperse(IntList *list, int value);

// Removes and loads ret with the front of the list.  Returns true if the
// operation is successful and false otherwise.
bool pop_front(IntList *list, int *ret);

// Removes and loads ret with the value at nth position in the list.  Returns
// true if the operation is successful and false otherwise (e.g., the nth index
// is not within the bounds of the list).
bool del(IntList *list, int n, int *ret);

///// }}} //////////////////////////////////////////////////////////////////////

///// Part 2: Implementation Choices and Memory Management {{{ /////////////////

// Appends the second list onto the end of the first list by allocating an
// entirely new list that is the result of appending the second onto the first.
// This new list is returned.  Both the first list and second list are
// unmodified.
IntList* append1(IntList *l1, IntList *l2);

// Appends the second list onto the end of the first list by allocating new
// nodes to insert onto the end of the first list.  The modified first list is
// returned.  The first list is modified and the second list is left unmodified.
IntList* append2(IntList *l1, IntList *l2);

// Appends the second list onto the end of the first list by taking the nodes of
// the second list and appending them to the end of the first list.  The
// modified first list is returned.  The second list should be empty after
// append3 completes.  Both lists are modified during this process.
IntList* append3(IntList *l1, IntList *l2);

// (NOTE: There are additional questions to answer in the write-up!)

///// }}} //////////////////////////////////////////////////////////////////////

#endif // _LIST_H
