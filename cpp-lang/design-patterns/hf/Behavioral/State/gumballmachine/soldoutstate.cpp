#include "soldoutstate.h"
#include "gumballmachine.h"

#include <iostream>
using std::cout;
using std::endl;

SoldOutState::SoldOutState(GumballMachine *gumballMachine)
    : State(gumballMachine)
{
}

void SoldOutState::insertQuarter()
{
    cout << "You can't insert a quarter, the machine is sold out" << endl;
}

void SoldOutState::ejectQuarter()
{
    cout << "You can't eject, you haven't inserted a quarter yet" << endl;
}

void SoldOutState::turnCrank()
{
    cout << "You turned but there are no gumballs" << endl;
}

void SoldOutState::dispense()
{
    cout << "No gumball dispensed" << endl;
}
