#ifndef CONDIMENTDECORATOR_H
#define CONDIMENTDECORATOR_H

#include "beverage.h"

class CondimentDecorator : public Beverage
{
public:
    CondimentDecorator(Beverage *b) : Beverage() {
        _beverage = b;
    }
    ~CondimentDecorator() {
        delete _beverage;
    }

protected:
    Beverage *_beverage;
};

#endif // CONDIMENTDECORATOR_H
