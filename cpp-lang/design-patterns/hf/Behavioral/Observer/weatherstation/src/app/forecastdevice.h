#ifndef FORECASTDEVICE_H
#define FORECASTDEVICE_H

#include "weatherdevice.h"

class ForecastDevice : public WeatherDevice
{
public:
    ForecastDevice(WeatherData *data);

private:
    void display() const;
};

#endif // FORECASTDEVICE_H
