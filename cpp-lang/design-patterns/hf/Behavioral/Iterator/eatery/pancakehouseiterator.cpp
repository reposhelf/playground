#include "pancakehouseiterator.h"

PancakeHouseIterator::PancakeHouseIterator(const std::vector<MenuItem *> items)
    : Iterator(),
      _items(items),
      _it(_items.cbegin())
{
}

bool PancakeHouseIterator::hasNext() const
{
    return _it != _items.cend();
}

MenuItem *PancakeHouseIterator::next() const
{
    return *_it++;
}
