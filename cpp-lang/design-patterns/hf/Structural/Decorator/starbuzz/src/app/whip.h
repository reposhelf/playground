#ifndef WHIP_H
#define WHIP_H

#include "condimentdecorator.h"

class Whip : public CondimentDecorator
{
public:
    Whip(Beverage *b) : CondimentDecorator(b) {
        _description = _beverage->description() + ", Whip";
    }
    ~Whip() {}

    double cost() const {
        return .10 + _beverage->cost();
    }
};

#endif // WHIP_H
