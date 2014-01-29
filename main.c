#include "list.h"
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char** argv) {
    IntList* list = mk_list();
    print_list(list);
	bool empty = is_empty(list);
    printf("is_empty(list) = 1? %d\n", empty);
    free_list(list);
    IntList* list2 = mk_list();
    return 0;
}

