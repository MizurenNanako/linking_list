#include <stdio.h>
#include "linking_list.h"

void pout(llist_int *list)
{
    for (int i = 0; i < list->length; ++i)
    {
        printf("index: %d\t data: %d\n", i, query_index_list_int(list, i));
    }
    puts("");
}

int main()
{
    llist_int *list = create_list_int(0);
    for (int i = 1; i < 10; ++i)
    {
        push_back_list_int(list, i);
    }
    pout(list);
    insert_index_list_int(list, 5, 999);
    insert_index_list_int(list, 3, 777);
    pout(list);
    delete_list_node_int(list, 8);
    delete_list_node_int(list, 8);
    pout(list);
    delete_list_int(list);
    return 0;
}