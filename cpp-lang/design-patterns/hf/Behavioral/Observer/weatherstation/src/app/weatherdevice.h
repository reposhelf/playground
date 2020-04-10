#ifndef WEATHERDEVICE_H
#define WEATHERDEVICE_H

class WeatherData;
class WeatherDevice
{
public:
    WeatherDevice(WeatherData *data);

    void update();

protected:
    virtual void display() const = 0;

    WeatherData *m_data;
    float m_temperature;
    float m_pressure;
    float m_humidity;
};

#endif // WEATHERDEVICE_H
