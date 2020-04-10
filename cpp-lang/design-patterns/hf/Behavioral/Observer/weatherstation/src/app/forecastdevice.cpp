#include "forecastdevice.h"

#include <iostream>

using namespace std;

ForecastDevice::ForecastDevice(WeatherData *data)
    : WeatherDevice(data)
{
}

void ForecastDevice::display() const
{
    cout << "Forecast: some information here..." << endl;
}
