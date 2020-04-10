#include "winnerstate.h"
#include "gumballmachine.h"

#include <iostream>
using std::cout;
using std::endl;

WinnerState::WinnerState(GumballMachine *gumballMachine)
    : State(gumballMachine)
{
}

void WinnerState::insertQuarter()
{
    cout << "You can't insert a quarter, the machine is sold out" << endl;
}

void WinnerState::ejectQuarter()
{
    cout << "You can't eject, you haven't inserted a quarter yet" << endl;
}

void WinnerState::turnCrank()
{
    cout << "Turning twice doesn't get you another gumballs" << endl;
}

void WinnerState::dispense()
{
    cout << "YOU'RE A WINNER! You get two gumballs for your quarter" << endl;
    cout << "A gumball comes rolling out the slot" << endl;
    m_gumballMachine->releaseBall();
    if (m_gumballMachine->count() == 0) {
        m_gumballMachine->setState(m_gumballMachine->state(GumballMachine::ST_SoldOut));
    } else {
        cout << "A gumball comes rolling out the slot" << endl;
        m_gumballMachine->releaseBall();
        if (m_gumballMachine->count() > 0) {
            m_gumballMachine->setState(m_gumballMachine->state(GumballMachine::ST_NoQuarter));
        } else {
            cout << "Oops, out of gumballs" << endl;
            m_gumballMachine->setState(m_gumballMachine->state(GumballMachine::ST_SoldOut));
        }
    }
}
