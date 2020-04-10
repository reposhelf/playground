#include "stereo.h"

#include <iostream>
using namespace std;

Stereo::Stereo(const char *location)
    : _location(location)
{
}

void Stereo::on() const
{
    cout << _location << " Stereo is On" << endl;
}

void Stereo::off() const
{
    cout << _location << " Stereo is Off" << endl;
}

void Stereo::setCD() const
{
    cout << _location << " Stereo is Set for CD input" << endl;
}

void Stereo::setDVD() const
{
    cout << _location << " Stereo is Set for DVD input" << endl;
}

void Stereo::setRadio() const
{
    cout << _location << " Stereo is Set for Radio" << endl;
}

void Stereo::setVolume() const
{
    cout << _location << " Stereo Volume is set to 11" << endl;
}
