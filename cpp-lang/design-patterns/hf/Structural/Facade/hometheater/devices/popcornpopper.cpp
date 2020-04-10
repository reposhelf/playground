#include "popcornpopper.h"

#include <iostream>
using namespace std;

PopcornPopper::PopcornPopper()
{
}

void PopcornPopper::on() const
{
    cout << "Popcorn Popper on" << endl;
}

void PopcornPopper::off() const
{
    cout << "Popcorn Popper off" << endl;
}

void PopcornPopper::pop() const
{
    cout << "Popcorn Popper popping popcorn!" << endl;
}
