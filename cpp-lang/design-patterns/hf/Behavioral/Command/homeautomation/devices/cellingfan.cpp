#include "cellingfan.h"

#include <iostream>
using namespace std;

CellingFan::CellingFan(const char *location)
    : _location(location),
      _speed(Off)
{
}

void CellingFan::high()
{
    _speed = static_cast<int>(High);

    cout << _location << " Celling Fan is Turn to High" << endl;
}

void CellingFan::medium()
{
    _speed = static_cast<int>(Medium);

    cout << _location << " Celling Fan is Turn to Medium" << endl;
}

void CellingFan::low()
{
    _speed = static_cast<int>(Low);

    cout << _location << " Celling Fan is Turn to Low" << endl;
}

void CellingFan::off()
{
    _speed = static_cast<int>(Off);

    cout << _location << " Celling Fan is Turn Off" << endl;
}
