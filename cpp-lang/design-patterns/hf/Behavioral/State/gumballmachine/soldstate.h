#ifndef SOLDSTATE_H
#define SOLDSTATE_H

#include "state.h"

class SoldState : public State
{
public:
    SoldState(GumballMachine *gumballMachine);

    void insertQuarter() override;
    void ejectQuarter() override;
    void turnCrank() override;
    void dispense() override;
};

#endif // SOLDSTATE_H
