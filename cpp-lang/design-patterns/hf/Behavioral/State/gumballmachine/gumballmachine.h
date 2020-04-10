#ifndef GUMBALLMACHINE_H
#define GUMBALLMACHINE_H

#include <ostream>

class State;
class GumballMachine
{
public:
    enum StateType { ST_NoQuarter, ST_HasQuarter, ST_SoldOut, ST_Sold, ST_Winner};

    GumballMachine(unsigned count);
    ~GumballMachine();

    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void releaseBall();
    void refill(int count);

    unsigned count() const { return m_count; }

    State *state(StateType stateType) const;
    void setState(State *state);

private:
    State *m_noQuarterState;
    State *m_hasQuarterState;
    State *m_soldOutState;
    State *m_soldState;
    State *m_winnerState;

    State *m_state;
    unsigned m_count;

    friend std::ostream &operator<<(std::ostream &os, const GumballMachine &gumballMachine);
};

#endif // GUMBALLMACHINE_H
