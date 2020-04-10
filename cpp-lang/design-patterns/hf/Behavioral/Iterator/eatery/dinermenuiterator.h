#ifndef DINERMENUITERATOR_H
#define DINERMENUITERATOR_H

#include "iterator.h"

class DinerMenuIterator : public Iterator
{
public:
    DinerMenuIterator(MenuItem **items, unsigned maxItems);

    bool hasNext() const;
    MenuItem *next() const;

private:
    MenuItem **_items;
    unsigned _maxItems;
    mutable unsigned _currentItem;
};

#endif // DINERMENUITERATOR_H
