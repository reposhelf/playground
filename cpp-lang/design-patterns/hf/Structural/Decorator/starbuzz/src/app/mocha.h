#ifndef MOCHA_H
#define MOCHA_H

#include "condimentdecorator.h"

class Mocha : public CondimentDecorator
{
public:
    Mocha(Beverage *b) : CondimentDecorator(b) {
        _description = _beverage->description() + ", Mocha";
    }
    ~Mocha() {}

    double cost() const {
        return .20 + _beverage->cost();
    }
};
#endif // MOCHA_H
