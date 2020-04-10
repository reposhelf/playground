#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <list>

class WeatherDevice;
class WeatherData
{
public:
    WeatherData();

    void setMeasurements(float, float, float);

    float temperature() const { return m_temperature; }
    void setTemperature(float);

    float pressure() const { return m_pressure; }
    void setPressure(float);

    float humidity() const { return m_humidity; }
    void setHumidity(float);

    void registerDevice(WeatherDevice *);
    void removeDevice(WeatherDevice *);
    void notifyAll() const;
    void measurementChanged() const;

private:
    std::list<WeatherDevice *> m_devices;
    float m_temperature;
    float m_pressure;
    float m_humidity;
};

#endif // WEATHERDATA_H
