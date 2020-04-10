#include <QtWebKit/QWebPage>
#include <QtWebKit/QWebFrame>
#include <QTimer>
#include <QDebug>

#include "weatherballoon.h"

#define UPDATE_TIME 900000  // 15 min

// constructor

WeatherBalloon::WeatherBalloon(const QString &cityName)
    : m_cityName(cityName)
{
    m_cloudValues.insert(1,   "01d");
    m_cloudValues.insert(-1,  "01n");
    m_cloudValues.insert(2,   "02d");
    m_cloudValues.insert(-2,  "02n");
    m_cloudValues.insert(3,   "03d");
    m_cloudValues.insert(31,  "03n");
    m_cloudValues.insert(4,   "04d");
    m_cloudValues.insert(-4,  "04n");
    m_cloudValues.insert(9,   "09d");
    m_cloudValues.insert(91,  "09n");
    m_cloudValues.insert(10,  "10d");
    m_cloudValues.insert(-10, "10n");
    m_cloudValues.insert(11,  "11d");
    m_cloudValues.insert(-11, "11n");
    m_cloudValues.insert(13,  "13d");
    m_cloudValues.insert(-13, "13n");
    m_cloudValues.insert(50,  "50d");
    m_cloudValues.insert(51, "50n");

    m_page = new QWebPage;
    m_timer = new QTimer;

    connect(m_page, SIGNAL(loadFinished(bool)), this, SLOT(readHtml()));
    connect(m_timer, SIGNAL(timeout()), this, SLOT(load()));

    m_timer->start(UPDATE_TIME);
    load();
}

// readHtml()

void WeatherBalloon::readHtml()
{
    m_data = m_page->mainFrame()->toHtml();
    qDebug() << m_data;
    findCityName();
    findTemperature(m_data);
    findCloudiness(m_data);
}

// load()

void WeatherBalloon::load()
{
    QUrl url("http://api.openweathermap.org/data/2.5/weather?q="
                     + m_cityName
                     + "&mode=xml&units=metric");
    m_page->mainFrame()->load(url);
}

// findCityName()

void WeatherBalloon::findCityName() const
{
    emit foundCityName(m_cityName);
    qDebug() << "City name: " << m_cityName;
}

// findTemperature()

void WeatherBalloon::findTemperature(const QString &data) const
{
    QStringList dataList = data.split("<");

    int i = 0;
    while (!dataList[++i].contains("temperature")) {}
    QString tempString = dataList[i];

    QString result;
    for (i = 0; i < tempString.length(); ++i) {
        if (tempString[i] == '\"') {
            for (int j = (++i); tempString[j] != '\"'; ++j)
                result += tempString[j];
            break;
        }
    }
    double temperature = QString(result).toDouble();
    emit foundTemperature(temperature);
    qDebug() << "Temperature: " << temperature;
}

// findCloudiness()

void WeatherBalloon::findCloudiness(const QString &data) const
{
    QStringList dataList = data.split("<");

    int i = 0;
    while (!dataList[++i].contains("icon")) {}
    QString tempString = dataList[i];
    dataList.clear();
    dataList = tempString.split(" ");

    i = 0;
    while (!dataList[++i].contains("icon")) {}
    tempString = dataList[i];

    QString result;
    for (i = 0; i < tempString.length(); ++i) {
        if (tempString[i] == '\"') {
            for (int j = (++i); tempString[j] != '\"'; ++j)
                result += tempString[j];
            break;
        }
    }

    int id = cloudinessID(result);
    emit foundCloudiness(id);
    qDebug() << "Cloudiness: " << result;
}

// cloudinessID()

int WeatherBalloon::cloudinessID(const QString &val) const
{
    QMapIterator<int, QString> it(m_cloudValues);
    while (it.hasNext()) {
        it.next();
        if (it.value() == val)
            return it.key();
    }
    return 0;
}
