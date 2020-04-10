#include "dinermenuiterator.h"
#include "menuitem.h"

#include <iostream>

DinerMenuIterator::DinerMenuIterator(MenuItem **items, unsigned maxItems)
    : Iterator(),
      _items(items),
      _maxItems(maxItems),
      _currentItem(0)
{
}

bool DinerMenuIterator::hasNext() const
{
    return _currentItem < _maxItems;
}

MenuItem *DinerMenuIterator::next() const
{
    return _items[_currentItem++];
}
