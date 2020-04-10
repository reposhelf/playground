#ifndef SOLDOUTSTATE_H
#define SOLDOUTSTATE_H

#include "state.h"

class SoldOutState : public State
{
public:
    SoldOutState(GumballMachine *gumballMachine);

    void insertQuarter() override;
    void ejectQuarter() override;
    void turnCrank() override;
    void dispense() override;
};

#endif // SOLDOUTSTATE_H
