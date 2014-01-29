#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>


int main(int* argc, char** argv) {
    IntList* list = mk_list(void);
    print_list(list);
    printf("is_empty(list) = 1? %d\n", is_empty(list));
    free_list(list);
    IntList* list = mk_list(void);
    
    return 0;
}


