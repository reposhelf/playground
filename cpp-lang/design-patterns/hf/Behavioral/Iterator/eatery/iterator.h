#ifndef ITERATOR_H
#define ITERATOR_H

class MenuItem;
class Iterator
{
public:
    Iterator();

    virtual bool hasNext() const = 0;
    virtual MenuItem *next() const = 0;
};

#endif // ITERATOR_H
