#include "cafemenuiterator.h"

CafeMenuIterator::CafeMenuIterator(const std::list<MenuItem *> &items)
    : Iterator(),
      _items(items),
      _it(_items.cbegin())
{
}

bool CafeMenuIterator::hasNext() const
{
    return _it != _items.cend();
}

MenuItem *CafeMenuIterator::next() const
{
    return *_it++;
}
