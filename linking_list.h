#ifndef _linking_list_h
#define _linking_list_h

#include <stdlib.h>

struct __node
{
    int data;
    struct __node *next;
};

typedef struct __node llist_node_int;

/* typedef struct
{
    int data;
    llist_node_int *next;
}llist_node_int; */

typedef struct
{
    unsigned long long length;
    llist_node_int *head;
} llist_int;

/// Create a list
/// \param first_element the first of the elements you want to store
/// \returns the head pointer of the list created
llist_int *create_list_int(int first_element);

/// Create a list node
/// \param data the data you want to store
/// \returns the pointer of the list node created
llist_node_int *create_list_node_int(int data);

/// Delete a list
/// \param target the list you want to destory
void delete_list_int(llist_int *target);

/// Delete a node in a list with an specific index
/// \param target_list the node you want to destory in
/// \param index the index, remember it starts with 0
void delete_list_node_int(llist_int *target_list, unsigned long long index);

/// Push an element to the back of the list
/// \param destination the list you want to push to
/// \param element the element you want to add to this list
void push_back_list_int(llist_int *destination, int element);

/// Query an element from a list with index
/// \param from the list to be query
/// \param index the index, remember it starts with 0
/// \returns the int stored int the match list with matching index
int query_index_list_int(llist_int *from, unsigned long long index);

///Insert an element from a list with index
/// \param destination the list to be insert
/// \param index the index, remember it starts with 0
/// \param data the data you inserting
void insert_index_list_int(llist_int *destination, unsigned long long index, int data);

llist_int *create_list_int(int first_element)
{
    llist_int *r = (llist_int *)malloc(sizeof(llist_int));
    r->head = create_list_node_int(first_element);
    r->length = 1;
    return r;
}

llist_node_int *create_list_node_int(int data)
{
    llist_node_int *r = (llist_node_int *)malloc(sizeof(llist_node_int));
    r->data = data;
    r->next = NULL;
    return r;
}

void delete_list_node_int(llist_int *target_list, unsigned long long index)
{
    if (index >= target_list->length)
    {
        return;
    }
    llist_node_int *r = target_list->head;
    if (index == 0)
    {
        target_list->head = r->next;
        free(r);
        --target_list->length;
        return;
    }
    if (index == target_list->length - 1)
    {
        for (int i = 1; i < index; ++i)
        {
            r = r->next;
        }
        free(r->next);
        r->next = NULL;
        --target_list->length;
        return;
    }
    for (int i = 1; i < index; ++i)
    {
        r = r->next;
    }
    llist_node_int *t = r->next;
    r->next = t->next;
    free(t);
    --target_list->length;
}

void push_back_list_int(llist_int *destination, int element)
{
    llist_node_int *c = destination->head, *n;
    for (int i = 1; i < destination->length; ++i)
    {
        c = c->next;
    }
    c->next = create_list_node_int(element);
    ++destination->length;
}

int query_index_list_int(llist_int *from, unsigned long long index)
{
    llist_node_int *r = from->head;
    for (int i = 0; i < from->length && i < index; ++i)
    {
        r = r->next;
    }
    return r->data;
}

void insert_index_list_int(llist_int *destination, unsigned long long index, int data)
{
    llist_node_int *r = destination->head, *t;
    for (int i = 0; i < destination->length && i < index; ++i)
    {
        r = r->next;
    }
    t = create_list_node_int(data);
    t->next = r->next;
    r->next = t;
    ++destination->length;
}

void delete_list_int(llist_int *target)
{
    llist_node_int *c = target->head, *n;
    for (int i = 0; i < target->length; ++i)
    {
        n = c;
        c = c->next;
        free(n);
    }
    free(target);
    target = NULL;
}

#endif