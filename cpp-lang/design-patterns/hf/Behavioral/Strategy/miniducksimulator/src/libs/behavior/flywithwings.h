#ifndef FLYWITHWINGS_H
#define FLYWITHWINGS_H

#include "flybehavior.h"

class FlyWithWings : public FlyBehavior
{
public:
    FlyWithWings();
    ~FlyWithWings();

    void fly() const;
};

#endif // FLYWITHWINGS_H
