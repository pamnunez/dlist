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
    if (list == NULL) { return; }
    DNode* cur = list->first;
    while (cur != NULL) {
        DNode* del = cur;
        cur = cur->next;
        free(del);
    }
    free(list);
}

void print_list(IntList *list) {
    if (list == NULL) { 
        printf("This list is NULL.");
        return;
    }
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
bool index_of(IntList *list, int value, int *ret) {
    DNode * cur = list->first;
    int index = 0;
    if (cur->value == value) {
        *ret = index;
        return true;
    }
    while(cur->value != value) {
        cur = cur->next;
        index++;
        if (cur == NULL) { return false; }
    }
    *ret = index;
    return true;
}


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
    if (list->first == NULL) {
		DNode* new = (DNode*) malloc(sizeof(DNode));
		new->value = value;
		new->prev = NULL;
		new->next = NULL;
		list->first = new;
    } else {
        DNode * new = (DNode*) malloc(sizeof(DNode));
        DNode * cur = list->first;
        new->prev = NULL;
        new->value = value;
        new->next = cur;
        cur->prev = new;
        list->first = new;
    }
}

// Inserts the given value into the nth position in the list.  Elements from
// nth index on are shifted to the right to make room.  Returns true if the
// operation is successful and false otherwise (e.g., the nth index is in the
// range 0 <= n <= len(l).
bool insert(IntList *list, int value, int n) {
    DNode* new = (DNode*) malloc(sizeof(DNode));
    new->value = value;
	DNode* cur = list->first;
    DNode* count = list->first;
    int length = 1;

	while(count->next != NULL) {
		length++;
		count = count->next;
	}
    
    if (n > (length-1)) { return 0; }

	if ((cur == NULL)&&(n == 0)) {
        list->first = new;
        return 1;
    }

    if (n == 0) {
        cur->prev = new;
        new->next = cur;
        list->first = new;
        return 1;
    }

    if (n == (length-1)) { 
    	DNode* temp = list->first;
		while(temp->next != NULL) {
			temp = temp->next;
		}
        new->prev = temp;
		new->next = NULL;
		temp->next = new;
        return 1;
    }

    int i;
    for (i = 0; i < n; i++) { cur = cur->next; }
    DNode* oldprev = cur->prev;
    new->prev = oldprev;
    new->next = cur;
    cur->prev = new;
    oldprev->next = new;
    return 1;
}

// Inserts the given integer between each pair of integers in the given list.
// For example, interspersing 9 between the following lists yields:
//
// [0, 1, 2]          ~> [0, 9, 1, 9, 2]
// [0, 1, 2, 3, 4, 5] ~> [0, 9, 1, 9, 2, 9, 3, 9, 4, 9, 5]
// [1]                ~> [1]
// []                 ~> []
//
// Note the cases for the list of one element and the empty list!
void intersperse(IntList *list, int value) {
    // if list empty or one long, do nothing.
    // if list is x long, the value will be inserted x-1 times
    // for loop, create a new node, add it before current (starting at second), 
    // then go next. if new current next is NULL, stop. if not, cur = cur->next
    DNode* cur = list->first;
    if ((cur == NULL)||(cur->next==NULL)) {
        return;
    }

    cur = cur->next;
    while (cur->next != NULL) {
        DNode * new = (DNode*) malloc(sizeof(DNode));
        new->value = value;
        DNode * oldprev = cur->prev;
        new->prev = oldprev;
        new->next = cur;
        cur->prev = new;
        oldprev->next = new;
        cur = cur->next;
        
    }
        DNode * new = (DNode*) malloc(sizeof(DNode));
        new->value = value;
        DNode * oldprev = cur->prev;
        new->prev = oldprev;
        new->next = cur;
        cur->prev = new;
        oldprev->next = new;

}

// Removes and loads ret with the front of the list.  Returns true if the
// operation is successful and false otherwise.
bool pop_front(IntList *list, int *ret) {
    DNode* cur = list->first;
    if (cur == NULL) { free(list); return 0; }
    if (cur->next == NULL) {
        *ret = cur->value;
        free(cur);
        free(list);
        return 1;
    }
    *ret = cur->value;
    DNode* newfirst = cur->next;
    newfirst->prev = NULL;
    list->first = newfirst;
    free(cur);
    return 1;
}

// Removes and loads ret with the value at nth position in the list.  Returns
// true if the operation is successful and false otherwise (e.g., the nth index
// is not within the bounds of the list).
bool del(IntList *list, int n, int *ret) {
	DNode* cur = list->first;
    DNode* count = list->first;
    int length = 1;
    int trigger = 0;

	while(count->next != NULL) { 
        length++;
		count = count->next;
	}
    printf("length list2 = %d\n", length);
    if (n >= length) { return 0; }

// if first,
    if (n == 0) {
	    printf("Trigger a %d\n", trigger++);
        if ((cur->next = NULL)) {
            printf("Trigger a-1");
            free(cur);
            free(list);
            return 1;
        } else {
	        printf("Trigger b %d\n", trigger++);
            *ret = cur->value;
            printf("Trigger b: ret = %d\n", *ret);
            DNode* newfirst = cur->next;
            //printf("newfirst->value = %d\n", cur->next->value); 
            newfirst->prev = NULL;
            list->first = newfirst;
            free(cur);
            return 1;
        }
    }

// if last,
    if (n == (length-1)) {
	    printf("Trigger c %d\n", trigger++);
        while(cur->next != NULL) {
            cur = cur->next;
        }
        *ret = cur->value;
        cur->prev->next = NULL;
        free(cur);
        return 1;
    }

// else... iterate through to n, change pointers and free

    int i;
    for (i = 0; i == n; i++) { cur = cur->next; }
	printf("Trigger d %d\n", trigger++);
    DNode* oldprev = cur->prev;
    DNode* oldnext = cur->next;
    
    oldprev->next = oldnext;
    oldnext->prev = oldprev;
    free(cur);
    return 1;
}















