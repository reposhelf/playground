#ifndef LINK_H
#define LINK_H

#include "item.h"

struct node
{
    Item item;
    node *next;
    node(Item x)
        : item(x),
          next(nullptr) {
    }
};
typedef node *link;

link randlist(int);
link scanlist(int&);
void showlist(link);
link sortlist(link);

link findmax(link);
link listselection(link);

#endif // LINK_H
