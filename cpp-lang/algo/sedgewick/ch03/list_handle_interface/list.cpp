#include "list.h"

link free_list;

void construct(int n)
{
    free_list = new node[n + 1];
    for (int i = 0; i < n; ++i)
        free_list[i].next = &free_list[i + 1];
    free_list[n].next = nullptr;
}

link newNode(int i)
{
    link x = remove(free_list);
    x->item = i;
    x->next = x;
    return x;
}

void deleteNode(link x)
{
    insert(free_list, x);
}

void insert(link x, link t)
{
    t->next = x->next;
    x->next = t;
}

link remove(link x)
{
    link t = x->next;
    x->next = t->next;
    return t;
}

link next(link x)
{
    return x->next;
}

Item item(link x)
{
    return x->item;
}
