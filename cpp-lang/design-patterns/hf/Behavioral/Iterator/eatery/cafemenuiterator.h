#ifndef CAFEMENUITERATOR_H
#define CAFEMENUITERATOR_H

#include "iterator.h"

#include <list>

class CafeMenuIterator : public Iterator
{
public:
    CafeMenuIterator(const std::list<MenuItem *> &items);

    bool hasNext() const;
    MenuItem *next() const;

private:
    std::list<MenuItem *> _items;
    mutable std::list<MenuItem *>::const_iterator _it;
};

#endif // CAFEMENUITERATOR_H
