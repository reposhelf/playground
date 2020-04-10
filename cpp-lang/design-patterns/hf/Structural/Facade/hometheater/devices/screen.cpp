#include "screen.h"

#include <iostream>
using namespace std;

Screen::Screen()
{
}

void Screen::up() const
{
    cout << "Theater Screen going up" << endl;
}

void Screen::down() const
{
    cout << "Theater Screen going down" << endl;
}
