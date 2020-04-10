#ifndef DECAF_H
#define DECAF_H

#include "beverage.h"

class Decaf : public Beverage
{
public:
    explicit Decaf() : Beverage() {
        _description = "Decaf";
    }
    ~Decaf() {}

    double cost() const {
        return 1.77;
    }
};

#endif // DECAF_H
