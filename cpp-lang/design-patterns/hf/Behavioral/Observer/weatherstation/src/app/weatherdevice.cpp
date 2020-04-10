#include "weatherdevice.h"
#include "weatherdata.h"

WeatherDevice::WeatherDevice(WeatherData *data)
    : m_data(data),
      m_temperature(0.0),
      m_pressure(0.0),
      m_humidity(0.0)
{
    m_data->registerDevice(this);
}

void WeatherDevice::update()
{
    if (!m_data)
        return;
    m_temperature = m_data->temperature();
    m_pressure = m_data->pressure();
    m_humidity = m_data->humidity();
    display();
}
