#include "link.h"

link randlist(int)
{
    // TODO
}

link scanlist(int &)
{
    // TODO
}

void showlist(link)
{
    // TODO
}

link sortlist(link)
{
    // TODO
}

link findmax(link)
{
    // TODO
}

link listselection(link h)
{
    node dummy(Item{0, 0.0});
    link head = &dummy;
    link out = nullptr;

    head->next = h;
    while (head->next != nullptr) {
        link max = findmax(head);
        link t = max->next;
        max->next = t->next;
        t->next = out;
        out = t;
    }

    return out;
}
