#ifndef WINNERSTATE_H
#define WINNERSTATE_H

#include "state.h"

class WinnerState : public State
{
public:
    WinnerState(GumballMachine *gumballMachine);

    void insertQuarter() override;
    void ejectQuarter() override;
    void turnCrank() override;
    void dispense() override;
};

#endif // WINNERSTATE_H
