#include "currentconditionsdevice.h"

#include <iostream>

using namespace std;

CurrentConditionsDevice::CurrentConditionsDevice(WeatherData *data)
    : WeatherDevice(data)
{
}

void CurrentConditionsDevice::display() const
{
    cout << "Current conditions: " << m_temperature << "F degrees and " << m_humidity << "% humidity" << endl;
}
