#include "garagedoor.h"

#include <iostream>
using namespace std;

GarageDoor::GarageDoor(const char *location)
    : _location(location)
{
}

void GarageDoor::up() const
{
    cout << _location << "Garage Door is Open" << endl;
}

void GarageDoor::down() const
{
    cout << _location << "Garage Door is Close" << endl;
}

void GarageDoor::stop() const
{
    cout << _location << "Garage Door is Stop" << endl;
}

void GarageDoor::lightOn() const
{
    cout << _location << "Garage Door's'Light is On" << endl;
}

void GarageDoor::lightOff() const
{
    cout << _location << "Garage Door's'Light is Off" << endl;
}
