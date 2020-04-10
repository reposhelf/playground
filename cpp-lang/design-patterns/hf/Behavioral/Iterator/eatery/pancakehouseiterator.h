#ifndef PANCAKEHOUSEITERATOR_H
#define PANCAKEHOUSEITERATOR_H

#include "iterator.h"

#include <vector>

class PancakeHouseIterator : public Iterator
{
public:
    PancakeHouseIterator(const std::vector<MenuItem *> items);

    bool hasNext() const;
    MenuItem *next() const;

private:
    std::vector<MenuItem *> _items;
    mutable std::vector<MenuItem*>::const_iterator _it;
};

#endif // PANCAKEHOUSEITERATOR_H
