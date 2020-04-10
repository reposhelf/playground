#ifndef CONNECTIONDATA_H
#define CONNECTIONDATA_H

#include <QString>

class ConnectionData
{
public:
    ConnectionData();

    const QString &host() const { return mHost; }
    const QString &port() const { return mPort; }

private:
    void read();

private:
    QString mHost;
    QString mPort;
};

#endif // CONNECTIONDATA_H
