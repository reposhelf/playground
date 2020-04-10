#include "item.h"

#include <cstdlib>
#include <iostream>

int operator<(const Item &lhs, const Item &rhs)
{
    return lhs.key < rhs.key;
}

int scan(Item &item)
{
    return std::cin >> item.key >> item.info ? 1 : 0;
}

void rand(Item &item)
{
    item.key = 1000 * (1.0 * std::rand() / RAND_MAX);
    item.info = 1.0 * std::rand() / RAND_MAX;
}

void show(const Item &item)
{
    std::cout << item.key << ' ' << item.info << std::endl;
}
