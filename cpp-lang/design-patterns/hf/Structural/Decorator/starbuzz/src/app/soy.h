#ifndef SOY_H
#define SOY_H

#include "condimentdecorator.h"

class Soy : public CondimentDecorator
{
public:
    Soy(Beverage *b) : CondimentDecorator(b) {
        _description = _beverage->description() + ", Soy";
    }
    ~Soy() {}

    double cost() const {
        return .15 + _beverage->cost();
    }
};

#endif // SOY_H
