#include "theaterlights.h"

#include <iostream>
using namespace std;

TheaterLights::TheaterLights()
{
}

void TheaterLights::on() const
{
    cout << "Theater Celling Lights on" << endl;
}

void TheaterLights::off() const
{
    cout << "Theater Celling Lights off" << endl;
}

void TheaterLights::dim(int val) const
{
    cout << "Theater Celling Lights dimming to " << val << "%" << endl;
}
