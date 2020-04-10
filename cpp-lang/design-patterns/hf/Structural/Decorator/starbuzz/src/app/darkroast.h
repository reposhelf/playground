#ifndef DARKROAST_H
#define DARKROAST_H

#include "beverage.h"

class DarkRoast : public Beverage
{
public:
    explicit DarkRoast() : Beverage() {
        _description = "Dark Roast Coffee";
    }
    ~DarkRoast() {}

    double cost() const {
        return .99;
    }
};

#endif // DARKROAST_H
