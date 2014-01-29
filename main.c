#include "list.h"
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char** argv) {
    IntList* list1 = mk_list();
    print_list(list1);
    printf("is_empty(list1) = 1? %d\n", is_empty(list1)); 
    printf("length(list1) = 0? %d\n", length(list1));
    free_list(list1);
    IntList* list2 = mk_list();
    push_back(list2, 4);
    push_back(list2, 5);
    printf("is_empty(list2) = 0? %d\n", is_empty(list2));
    printf("length(list2) = 2? %d\n", length(list2));
    print_list(list2);
    printf("sum(list2) = 9? %d\n", sum(list2));
    free_list(list2);
    
 
    return 0;
}

