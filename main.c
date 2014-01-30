#include "list.h"
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char** argv) {
/*    IntList* list1 = mk_list();
    print_list(list1);
    printf("is_empty(list1) = 1? %d\n", is_empty(list1)); 
    printf("length(list1) = 0? %d\n", length(list1));
    free_list(list1);
*/    IntList* list2 = mk_list();
    push_back(list2, 4);
    push_back(list2, 5);
/*    printf("is_empty(list2) = 0? %d\n", is_empty(list2));
    printf("length(list2) = 2? %d\n", length(list2));
    print_list(list2);
    printf("sum(list2) = 9? %d\n", sum(list2));
    int ret1, ret2, ret3;
    printf("index_of(list2, 4, ret1) = true? %d\n", index_of(list2, 4, &ret1));
    printf("index_of(list2, 5, ret2) = true? %d\n", index_of(list2, 5, &ret2));
    printf("index_of(list2, 6, ret3) = false? %d\n", index_of(list2, 6, &ret3));
    printf("index_of(list2, 4, ret1), ret1 = 0? %d\n", ret1);
    printf("index_of(list2, 5, ret2), ret2 = 1? %d\n", ret2);
*/
    push_front(list2, 6);
    print_list(list2);
/*
    printf("index_of(list2, 4, ret1) = true? %d\n", index_of(list2, 4, &ret1));
    printf("index_of(list2, 5, ret2) = true? %d\n", index_of(list2, 5, &ret2));
    printf("index_of(list2, 6, ret3) = true? %d\n", index_of(list2, 6, &ret3));
    printf("index_of(list2, 4, ret1), ret1 = 1? %d\n", ret1);
    printf("index_of(list2, 5, ret2), ret2 = 2? %d\n", ret2);
    printf("index_of(list2, 6, ret3), ret2 = 0? %d\n", ret3);
*/
    insert(list2, 8, 0);
    print_list(list2);
    insert(list2, 9, 2);
    print_list(list2);
    insert(list2, 7, 4);
    print_list(list2);

    intersperse(list2, 3);
    print_list(list2);

    IntList* list3 = mk_list();
    push_back(list3, 4);
    push_back(list3, 5);
    intersperse(list3, 2);
    print_list(list3);

    int pop;
    pop_front(list3, &pop);
    print_list(list3);
    printf("pop = %d\n", pop);

    pop_front(list3, &pop);
    print_list(list3);
    printf("pop = %d\n", pop);

    pop_front(list3, &pop);
//    print_list(list3);
    printf("pop = %d\n", pop);


    free_list(list2);
//    free_list(list3);
 
    return 0;
}

