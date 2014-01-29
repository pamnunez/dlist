#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>


int main(int* argc, char** argv) {
    IntList* list =  mk_list(void);
    print_list(list);
    is_empty(list);

    return 0;
}


