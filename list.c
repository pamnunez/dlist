#include "list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

IntList* mk_list(void) {
    IntList* result = (IntList*) malloc(sizeof(IntList));
    result->first = NULL;
    return result;
}

void free_list(IntList *list) {
    DNode* cur = list->first;
    while (cur != NULL) {
        DNode* del = cur;
        cur = cur->next;
        free(del);
    }
    free(list);
}

void print_list(IntList *list) {
	printf("[");
	DNode* cur = list->first;
	while (cur != NULL) {
		printf(" %d ", cur->value);
		cur = cur->next;
	}
	printf("]\n");
}

bool is_empty(IntList *list) {
    if (list->first == NULL) {
		return 1;
	} else {
		return 0;
	}
}

int length(IntList *list) {
	DNode* cur = list->first;
	if (cur == NULL) { return 0; }
	int result = 1;
	while(cur->next != NULL) {
		result++;
		cur = cur->next;
	}
	return result;
}

// Returns the sum of the values in the given list.
int sum(IntList *list) {
    DNode* cur = list->first;
    if (cur == NULL) { return 0; }
    int sum = 0;
    while (cur->next != NULL) {
        sum += cur->value;
        cur = cur->next;
    }
    return sum+=cur->value; 
}

// Loads ret with the index of the first occurrence of value in the list.
// Returns true if the operation is successful and false otherwise.
bool index_of(IntList *list, int value, int *ret);


// Inserts the given value into the end of the list.
void push_back(IntList *list, int value) {
	if (list->first == NULL) {
		DNode* new = (DNode*) malloc(sizeof(DNode));
		new->value = value;
		new->prev = NULL;
		new->next = NULL;
		list->first = new;
	} else {
		DNode* cur = list->first;
		while(cur->next != NULL) {
			cur = cur->next;
		}
		DNode* new = (DNode*) malloc(sizeof(DNode));
		new->value = value;
		new->prev = cur;
		new->next = NULL;
		cur->next = new;
	}
}

// Pushes the given value onto the front of the list.
void push_front(IntList *list, int value) {

}

/*
void free_list(LinkedList *l) {
	Node *cur = l->first;
	while (cur != NULL) {
		Node *next = cur->next;
		free(next);
	}	
	free(l);
}
*/

