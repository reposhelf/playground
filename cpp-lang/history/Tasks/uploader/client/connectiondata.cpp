#include "connectiondata.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

ConnectionData::ConnectionData()
{
    read();
}

void ConnectionData::read()
{
    QFile file(":/server_data.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qCritical() << "ConnectioData: cannot open JSON file";
        return;
    }
    QString data = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject object = document.object();
    mHost = object["Host"].toString();
    mPort = object["Port"].toString();
}
