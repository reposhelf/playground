#include "sslsocketlistener.h"

#include <QSslSocket>
#include <QFile>
#include <QDir>

#include <QDebug>

#include <iostream>
#include <string>


SslSocketListener::SslSocketListener(quintptr socketDescriptor, QObject *parent)
    : QThread(parent),
      mSocketDescriptor(socketDescriptor),
      mSocket(Q_NULLPTR)
{
    connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));

    connect(&mHttpMultiPartHandler, SIGNAL(fileReady(QString,QByteArray)),
            this, SIGNAL(fileReady(QString,QByteArray)));
    connect(&mHttpMultiPartHandler, SIGNAL(error()),
            this, SLOT(onHttpMultiPartHandlerError()));
}

void SslSocketListener::run()
{
    qDebug() << Q_FUNC_INFO;

    mSocket = new QSslSocket;
    if (!mSocket->setSocketDescriptor(mSocketDescriptor))
    {
        emit errorOccured(mSocket->errorString());
        return;
    }

    mSocket->setLocalCertificate(":/localhost.pem");
    mSocket->setPrivateKey(":/localhost.key");
    mSocket->setProtocol(QSsl::TlsV1_2);

    mSocket->startServerEncryption();

    connect(mSocket, SIGNAL(connected()), this, SLOT(onSocketConnected()), Qt::DirectConnection);
    connect(mSocket, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()), Qt::DirectConnection);
    connect(mSocket, SIGNAL(disconnected()), this, SLOT(onSocketDisconnected()));
    connect(mSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(onSocketError(QAbstractSocket::SocketError)), Qt::DirectConnection);
    connect(mSocket, SIGNAL(sslErrors(QList<QSslError>)),
            this, SLOT(onSocketSslErrors(QList<QSslError>)), Qt::DirectConnection);


    qDebug() << "New client connected with socket ID: " << mSocketDescriptor;

    exec();
}

void SslSocketListener::onSocketReadyRead()
{
    qDebug() << Q_FUNC_INFO;

    mHttpMultiPartHandler.addPartitionedData(mSocket->readAll());
}

void SslSocketListener::onSocketConnected()
{
    qDebug() << Q_FUNC_INFO;
}

void SslSocketListener::onSocketDisconnected()
{
    qDebug() << Q_FUNC_INFO;

    mSocket->deleteLater();
    exit(0);
}

void SslSocketListener::onSocketError(QAbstractSocket::SocketError socketError)
{
    qDebug() << socketError;
}

void SslSocketListener::onSocketSslErrors(const QList<QSslError> &list)
{
    qDebug() << "SSL socket errors:";
    foreach (auto i, list)
        qDebug() << i.errorString();
}

void SslSocketListener::onHttpMultiPartHandlerError()
{
    emit errorOccured(mHttpMultiPartHandler.errorString());

    mHttpMultiPartHandler.reset();
}
