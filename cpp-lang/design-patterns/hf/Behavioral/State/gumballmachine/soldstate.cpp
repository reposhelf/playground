#include "soldstate.h"
#include "gumballmachine.h"

#include <iostream>
using std::cout;
using std::endl;

SoldState::SoldState(GumballMachine *gumballMachine)
    : State(gumballMachine)
{
}

void SoldState::insertQuarter()
{
    cout << "You can't insert a quarter, the machine is sold out" << endl;
}

void SoldState::ejectQuarter()
{
    cout << "You can't eject, you haven't inserted a quarter yet" << endl;
}

void SoldState::turnCrank()
{
    cout << "Turning twice doesn't get you another gumballs" << endl;
}

void SoldState::dispense()
{
    cout << "A gumball comes rolling out the slot" << endl;
    m_gumballMachine->releaseBall();
    if (m_gumballMachine->count() > 0) {
        m_gumballMachine->setState(m_gumballMachine->state(GumballMachine::ST_NoQuarter));
    } else {
        cout << "Oops, out of gumballs" << endl;
        m_gumballMachine->setState(m_gumballMachine->state(GumballMachine::ST_SoldOut));
    }
}
