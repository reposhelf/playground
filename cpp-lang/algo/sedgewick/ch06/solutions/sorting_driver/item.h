#ifndef ITEM_H
#define ITEM_H

#include <iostream>

typedef struct record
{
    int key;
    float info;
} Item;

int operator<(const Item &lhs, const Item &rhs);
std::istream &operator>>(std::istream &is, Item &item);
void rand(Item &item);
std::ostream &operator<<(std::ostream &os, const Item &item);

#endif // ITEM_H
