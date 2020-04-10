#include <QPainter>
#include <QRectF>

#include "weatherwidget.h"
#include "weatherballoon.h"

// constructor

WeatherWidget::WeatherWidget(QWidget *parent) : QWidget(parent)
{
    resize(400, 250);
    m_temperature = "?";
    m_cityName = "No data";
    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);

    weatherBalloon = new WeatherBalloon("Vinnytsia");

    connect(weatherBalloon, SIGNAL(foundTemperature(double)), this, SLOT(temperature(double)));
    connect(weatherBalloon, SIGNAL(foundCityName(QString)), this, SLOT(cityName(QString)));
    connect(weatherBalloon, SIGNAL(foundCloudiness(int)), this, SLOT(cloudiness(int)));

    setWindowTitle(tr("Weather Widget"));
}

// paintEvent()

void WeatherWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setBrush(QColor(10, 10, 10));
    QRectF windowRect(0, 0, width(), height());
    painter.drawRect(windowRect);

    painter.setBrush(Qt::white);
    painter.setPen(Qt::white);
    QFont cityFont("Times", 14);
    painter.setFont(cityFont);
    QRectF cityRect(0, 0, width(), 20);
    painter.drawText(cityRect, Qt::AlignHCenter | Qt::AlignBottom, m_cityName);

    painter.setFont(QFont("Times", 46));

    QRectF temperatureRect(300, cityRect.height(), 100, (height() - cityRect.height()) / 3);
    painter.drawText(temperatureRect, Qt::AlignLeft | Qt::AlignBottom, m_temperature);


    QRectF imageRect(0, cityRect.height(), 300, height() - cityRect.height() * 2);
    painter.drawImage(imageRect, m_cloudImage, m_cloudRect);
}

// temperature()
#include <QDebug>
void WeatherWidget::temperature(double temperature)
{
    qDebug() << temperature;
    int temp = temperature;
    m_temperature = QString::number(temp) + "°";
    repaint();
}

// cityName()

void WeatherWidget::cityName(const QString &city)
{
    m_cityName = "Now in " + city;
    repaint();
}

// cloudiness()

void WeatherWidget::cloudiness(int cloudID)
{
    initialImagePos(cloudID);
    repaint();
}

// initialImagePos()

void WeatherWidget::initialImagePos(int cloudID) {
    initialImage(cloudID);

    switch (cloudID) {
    case 1:                                      // sky is clear (day)
        m_cloudRect.setRect(-40, -20, 300, 210);
        break;
    case 2:                                      // few clouds (day)
        m_cloudRect.setRect(220, -20, 300, 210);
        break;
    case 3: case 50: case 31: case 51:           // scattered clouds (mixed)
        m_cloudRect.setRect(-20, 180, 300, 210);
        break;
    case 4:                                      // broken clouds (day)
        m_cloudRect.setRect(540, -20, 300, 210);
        break;
    case 9: case 91:                             // shower rain (mixed)
        m_cloudRect.setRect(270, 420, 300, 210);
        break;
    case 10:                                     // rain (day)
        m_cloudRect.setRect(-20, 400, 300, 210);
        break;
    case 11:                                     // thunderstorm (day)
        m_cloudRect.setRect(570, 420, 300, 210);
        break;
    case 13:                                     // snow (day)
        m_cloudRect.setRect(270, 180, 300, 210);
        break;
    case -1:                                     // sky is clear (night)
        m_cloudRect.setRect(-20, 240, 300, 210);
        break;
    case -2:                                     // few clouds (night)
        m_cloudRect.setRect(563, 430, 300, 210);
        break;
    case -4:                                     // broken clouds (night)
        m_cloudRect.setRect(270, 430, 300, 210);
        break;
    case -10:                                    // rain (night)
        m_cloudRect.setRect(270, 0, 300, 210);
        break;
    case -11:                                    // thunderstorm (night)
        m_cloudRect.setRect(263, 220, 300, 210);
        break;
    case -13:                                    // snow (night)
        m_cloudRect.setRect(-20, 0, 300, 210);
        break;
    }
}

// initialImage()

void WeatherWidget::initialImage(int cloudID) {
    if (cloudID < 0)
        m_cloudImage = QImage(":/images/test/night.jpg");
    else
        m_cloudImage = QImage(":/images/test/day.jpg");
}
