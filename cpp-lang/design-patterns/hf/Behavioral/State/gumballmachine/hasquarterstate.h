#ifndef HASQUARTERSTATE_H
#define HASQUARTERSTATE_H

#include "state.h"

class HasQuarterState : public State
{
public:
    HasQuarterState(GumballMachine *gumballMachine);

    void insertQuarter() override;
    void ejectQuarter() override;
    void turnCrank() override;
    void dispense() override;
};

#endif // HASQUARTERSTATE_H
