#include "gumballmachine.h"
#include "noquarterstate.h"
#include "hasquarterstate.h"
#include "soldoutstate.h"
#include "soldstate.h"
#include "winnerstate.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cassert>

GumballMachine::GumballMachine(unsigned count)
    : m_noQuarterState(new NoQuarterState(this)),
      m_hasQuarterState(new HasQuarterState(this)),
      m_soldOutState(new SoldOutState(this)),
      m_soldState(new SoldState(this)),
      m_winnerState(new WinnerState(this)),
      m_state(m_soldOutState),
      m_count(count)
{
    if (m_count > 0)
        m_state = m_noQuarterState;
}

GumballMachine::~GumballMachine()
{
    delete m_noQuarterState;
    delete m_hasQuarterState;
    delete m_soldOutState;
    delete m_soldState;
    delete m_winnerState;
}

void GumballMachine::insertQuarter()
{
    m_state->insertQuarter();
}

void GumballMachine::ejectQuarter()
{
    m_state->ejectQuarter();
}

void GumballMachine::turnCrank()
{
    m_state->turnCrank();
    m_state->dispense();
}

void GumballMachine::releaseBall()
{
    if (m_count > 0) --m_count;
}

void GumballMachine::refill(int count)
{
    m_count = count;
    m_state = m_noQuarterState;
    cout << "Gumball Machine is refilled" << endl;
}

State *GumballMachine::state(StateType stateType) const
{
    switch (stateType) {
    case ST_NoQuarter: return m_noQuarterState;
    case ST_HasQuarter: return m_hasQuarterState;
    case ST_SoldOut: return m_soldOutState;
    case ST_Sold: return m_soldState;
    case ST_Winner: return m_winnerState;
    default: return nullptr;
    }
}

void GumballMachine::setState(State *state)
{
    assert(state);
    m_state = state;
}

std::ostream &operator<<(std::ostream &os, const GumballMachine &gumballMachine)
{
    string state2str = (gumballMachine.m_count == 0)
            ? "sold out"
            : "waiting for quarter";

    os << "Mighty Gumball, Inc\n"
       << "C++-enabled Standing Gumball Model #2004\n"
       << "Inventory: " << gumballMachine.m_count << " gumballs\n"
       << "Machine is " << state2str;

    return os;
}
