#ifndef WEATHERWIDGET_H
#define WEATHERWIDGET_H

#include <QWidget>


class WeatherBalloon;

class WeatherWidget : public QWidget
{
    Q_OBJECT

public:
    WeatherWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void temperature (double temperature);
    void cityName    (const QString &city);
    void cloudiness  (int cloudID);

private:
    void initialImagePos (int);
    void initialImage    (int);

    WeatherBalloon *weatherBalloon;

    QString  m_temperature;
    QString  m_cityName;
    QRectF   m_cloudRect;
    QImage   m_cloudImage;
};

#endif // WEATHERWIDGET_H
