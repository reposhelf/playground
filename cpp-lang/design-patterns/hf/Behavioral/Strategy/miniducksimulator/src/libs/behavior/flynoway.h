#ifndef FLYNOWAY_H
#define FLYNOWAY_H

#include "flybehavior.h"

class FlyNoWay : public FlyBehavior
{
public:
    FlyNoWay();
    ~FlyNoWay();

    void fly() const;
};

#endif // FLYNOWAY_H
