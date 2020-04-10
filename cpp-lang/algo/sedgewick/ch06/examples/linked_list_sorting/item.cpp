#include "item.h"

#include <cstdlib>

int operator<(const Item &lhs, const Item &rhs)
{
    return lhs.key < rhs.key;
}

std::istream &operator>>(std::istream &is, Item &item)
{
    return is >> item.key >> item.info;
}

std::ostream &operator<<(std::ostream &os, const Item &item)
{
    return os << item.key << ' ' << item.info;
}

void rand(Item &item)
{
    item.key = 1000 * (1.0 * std::rand() / RAND_MAX);
    item.info = 1.0 * std::rand() / RAND_MAX;
}
