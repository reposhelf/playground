#include "statisticsdevice.h"

#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

StatisticsDevice::StatisticsDevice(WeatherData *data)
    : WeatherDevice(data),
      m_temperatures(),
      m_minTemperature(0.0),
      m_maxTemperature(0.0)
{
}

void StatisticsDevice::display() const
{
    m_temperatures.push_back(m_temperature);

    const int avg = accumulate(m_temperatures.begin(), m_temperatures.end(), 0.0) / m_temperatures.size();
    const int min = *min_element(m_temperatures.begin(), m_temperatures.end());
    const int max = *max_element(m_temperatures.begin(), m_temperatures.end());

    cout << "Avg/Max/Min temperature = " << avg << "/" << max << "/" << min << endl;
}
