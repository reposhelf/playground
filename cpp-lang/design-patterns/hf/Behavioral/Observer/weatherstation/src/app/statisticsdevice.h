#ifndef STATISTICSDEVICE_H
#define STATISTICSDEVICE_H

#include "weatherdevice.h"

#include <list>

class StatisticsDevice : public WeatherDevice
{
public:
    StatisticsDevice(WeatherData *data);

private:
    void display() const;

    mutable std::list<float> m_temperatures;
    float m_minTemperature;
    float m_maxTemperature;
};

#endif // STATISTICSDEVICE_H
