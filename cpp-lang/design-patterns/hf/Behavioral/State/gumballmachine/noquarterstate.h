#ifndef NOQUARTERSTATE_H
#define NOQUARTERSTATE_H

#include "state.h"

class NoQuarterState : public State
{
public:
    NoQuarterState(GumballMachine *gumballMachine);

    void insertQuarter() override;
    void ejectQuarter() override;
    void turnCrank() override;
    void dispense() override;
};

#endif // NOQUARTERSTATE_H
