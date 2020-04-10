#ifndef HOUSEBLEND_H
#define HOUSEBLEND_H

#include "beverage.h"

class HouseBlend : public Beverage
{
public:
    explicit HouseBlend() : Beverage() {
        _description = "House Blend Coffe";
    }
    ~HouseBlend() {}

    double cost() const {
        return .89;
    }
};

#endif // HOUSEBLEND_H
