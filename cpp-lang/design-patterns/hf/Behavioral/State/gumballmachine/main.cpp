#include "gumballmachine.h"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    GumballMachine gumballMachine(5);

    cout << gumballMachine << endl << endl;
    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    cout << endl;

    cout << gumballMachine << endl << endl;
    gumballMachine.insertQuarter();
    gumballMachine.ejectQuarter();
    gumballMachine.turnCrank();
    cout << endl;

    cout << gumballMachine << endl << endl;
    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    gumballMachine.ejectQuarter();
    cout << endl;

    cout << gumballMachine << endl << endl;
    gumballMachine.insertQuarter();
    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    cout << endl;

    cout << gumballMachine << endl << endl;;

    gumballMachine.refill(100);
    cout << endl;

    cout << gumballMachine << endl;

    return 0;
}
