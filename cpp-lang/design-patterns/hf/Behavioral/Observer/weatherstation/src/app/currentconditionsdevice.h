#ifndef CURRENTCONDITIONSDEVICE_H
#define CURRENTCONDITIONSDEVICE_H

#include "weatherdevice.h"

class CurrentConditionsDevice : public WeatherDevice
{
public:
    CurrentConditionsDevice(WeatherData *data);

private:
    void display() const;
};

#endif // CURRENTCONDITIONSDEVICE_H
