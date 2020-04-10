#include "light.h"

#include <iostream>
using namespace std;

Light::Light(const char *location)
    : _location(location)
{
}

void Light::on() const
{
    cout << _location << " Light is On" << endl;
}

void Light::off() const
{
    cout << _location << " Light is Off" << endl;
}
