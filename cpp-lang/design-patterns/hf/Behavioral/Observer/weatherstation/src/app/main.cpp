#include "weatherdata.h"
#include "currentconditionsdevice.h"
#include "statisticsdevice.h"
#include "forecastdevice.h"

#include <iostream>

using namespace std;

int main()
{
    WeatherData data;
    CurrentConditionsDevice currentConditions(&data);
    StatisticsDevice statistics(&data);
    ForecastDevice forecast(&data);

    data.setMeasurements(80.0, 65.0, 30.4);
    data.setMeasurements(82.0, 70.0, 29.2);
    data.setMeasurements(78.0, 90.0, 29.2);

    return 0;
}
