#include "weatherdata.h"
#include "weatherdevice.h"

using namespace std;

WeatherData::WeatherData()
    : m_devices(),
      m_temperature(0.0),
      m_pressure(0.0),
      m_humidity(0.0)
{
}

void WeatherData::setMeasurements(float t, float h, float p)
{
    setTemperature(t);
    setHumidity(h);
    setPressure(p);
    measurementChanged();
}

void WeatherData::setTemperature(float t)
{
    m_temperature = t;
}

void WeatherData::setPressure(float p)
{
    m_pressure = p;
}

void WeatherData::setHumidity(float h)
{
    m_humidity = h;
}

void WeatherData::registerDevice(WeatherDevice *d)
{
    m_devices.push_back(d);
}

void WeatherData::removeDevice(WeatherDevice *d)
{
    m_devices.remove(d);
}

void WeatherData::notifyAll() const
{
    for (WeatherDevice *d : m_devices)
        d->update();
}

void WeatherData::measurementChanged() const
{
    notifyAll();
}
