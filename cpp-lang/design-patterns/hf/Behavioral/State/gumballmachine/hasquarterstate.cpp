#include "hasquarterstate.h"
#include "gumballmachine.h"

#include <iostream>
using std::cout;
using std::endl;

HasQuarterState::HasQuarterState(GumballMachine *gumballMachine)
    : State(gumballMachine)
{
}

void HasQuarterState::insertQuarter()
{
    cout << "You can't insert another quarter" << endl;
}

void HasQuarterState::ejectQuarter()
{
    cout << "Quarter returned" << endl;
    m_gumballMachine->setState(m_gumballMachine->state(GumballMachine::ST_NoQuarter));
}

void HasQuarterState::turnCrank()
{
    cout << "You turned..." << endl;
    if (m_gumballMachine->count() == 4)
        m_gumballMachine->setState(m_gumballMachine->state(GumballMachine::ST_Winner));
    else
        m_gumballMachine->setState(m_gumballMachine->state(GumballMachine::ST_Sold));
}

void HasQuarterState::dispense()
{
    cout << "No gumball dispensed" << endl;
}
