#ifndef WEATHERBALLOON_H
#define WEATHERBALLOON_H

#include <QObject>
#include <QMap>


class QWebPage;
class QTimer;

class WeatherBalloon : public QObject
{
    Q_OBJECT

public:
    WeatherBalloon(const QString &cityName);

private slots:
    void readHtml();
    void load();

signals:
    void foundCityName    (const QString &city) const;
    void foundTemperature (double temperature) const;
    void foundCloudiness  (int id) const;

private:
    void findCityName     () const;
    void findTemperature  (const QString &data) const;
    void findCloudiness   (const QString &data) const;
    int  cloudinessID     (const QString &val) const;

    QWebPage *m_page;
    QTimer   *m_timer;

    QString            m_cityName;
    QString            m_data;
    QMap<int, QString> m_cloudValues;
};

#endif // WEATHERBALLOON_H
