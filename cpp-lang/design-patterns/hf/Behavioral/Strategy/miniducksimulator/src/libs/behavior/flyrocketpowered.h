#ifndef FLYROCKETPOWERED_H
#define FLYROCKETPOWERED_H

#include "flybehavior.h"

class FlyRocketPowered : public FlyBehavior
{
public:
    FlyRocketPowered();
    ~FlyRocketPowered();

    void fly() const;
};

#endif // FLYROCKETPOWERED_H
