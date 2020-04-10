#include "sslserver.h"
#include "sslsocketlistener.h"

#include <QFile>
#include <QDir>

#include <QDebug>

SslServer::SslServer(quint16 port, const QString &dirToSave, QObject *parent)
    : QTcpServer(parent),
      mPort(port),
      mDirToSave(dirToSave)
{
}

void SslServer::startServer()
{
    if (listen(QHostAddress::Any, mPort))
        qDebug() << "Server starts on port: " << mPort;
    else
        qDebug() << "Server can't starts on port: " << mPort;
}

void SslServer::incomingConnection(qintptr socketDescriptor)
{
    SslSocketListener *socketListener = new SslSocketListener(socketDescriptor, this);
    connect(socketListener, SIGNAL(fileReady(QString,QByteArray)),
            this, SLOT(saveFile(QString,QByteArray)), Qt::DirectConnection);
    connect(socketListener, SIGNAL(errorOccured(QString)),
            this, SLOT(onSslListenerErrorOccured(QString)), Qt::DirectConnection);
    socketListener->start();
}

void SslServer::saveFile(const QString &fileName, const QByteArray &fileContent)
{
        QFile file(QDir(mDirToSave).path() + QDir::separator() + fileName);
        if (!file.open(QIODevice::WriteOnly))
            qDebug() << Q_FUNC_INFO << ": Cannot save file";
        file.write(fileContent);
}

void SslServer::onSslListenerErrorOccured(const QString &error)
{
    qDebug() << error;
}
