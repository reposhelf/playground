#ifndef ESPRESSO_H
#define ESPRESSO_H

#include "beverage.h"

class Espresso : public Beverage
{
public:
    explicit Espresso() : Beverage() {
        _description = "Espresso";
    }
    ~Espresso() {}

    double cost() const {
        return 1.99;
    }
};

#endif // ESPRESSO_H
