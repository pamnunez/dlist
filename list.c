#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

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

#endif // _LIST_H
