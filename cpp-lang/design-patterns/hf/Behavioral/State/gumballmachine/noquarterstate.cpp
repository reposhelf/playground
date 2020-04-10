#include "noquarterstate.h"
#include "gumballmachine.h"

#include <iostream>
using std::cout;
using std::endl;

NoQuarterState::NoQuarterState(GumballMachine *gumballMachine)
    : State(gumballMachine)
{
}

void NoQuarterState::insertQuarter()
{
    cout << "You inserted the quarter" << endl;
    m_gumballMachine->setState(m_gumballMachine->state(GumballMachine::ST_HasQuarter));
}

void NoQuarterState::ejectQuarter()
{
    cout << "You haven't inserted a quarter" << endl;
}

void NoQuarterState::turnCrank()
{
    cout << "You turned but there is no quarter" << endl;
}

void NoQuarterState::dispense()
{
    cout << "You need to pay first" << endl;
}
