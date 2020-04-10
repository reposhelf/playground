#include "wildturkey.h"

#include <iostream>
using namespace std;

WildTurkey::WildTurkey()
    : Turkey()
{
}

WildTurkey::~WildTurkey()
{
}

void WildTurkey::gobble() const
{
    cout << "Gobble" << endl;
}

void WildTurkey::fly() const
{
    for (int i = 0; i < 5; ++i)
    {
        cout << "I can fly at short distances" << endl;
    }
}
