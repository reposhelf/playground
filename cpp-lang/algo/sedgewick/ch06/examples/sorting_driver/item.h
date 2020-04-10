#ifndef ITEM_H
#define ITEM_H

typedef struct record
{
    int key;
    float info;
} Item;

int operator<(const Item &lhs, const Item &rhs);
int scan(Item &item);
void rand(Item &item);
void show(const Item &item);

#endif // ITEM_H
