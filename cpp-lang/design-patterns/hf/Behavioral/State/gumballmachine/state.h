#ifndef STATE_H
#define STATE_H

class GumballMachine;
class State
{
public:
    State(GumballMachine *gumballMachine);
    virtual ~State();

    virtual void insertQuarter() = 0;
    virtual void ejectQuarter() = 0;
    virtual void turnCrank() = 0;
    virtual void dispense() = 0;

protected:
    GumballMachine *m_gumballMachine;
};

#endif // STATE_H
