#ifndef SSLSOCKETLISTENER_H
#define SSLSOCKETLISTENER_H

#include "httpmultiparthandler.h"

#include <QThread>
#include <QAbstractSocket>

class QSslSocket;
class QSslError;
class SslSocketListener : public QThread
{
    Q_OBJECT
public:
    SslSocketListener(quintptr socketDescriptor, QObject *parent = Q_NULLPTR);

    void run();

signals:
    void fileReady(const QString &fileName, const QByteArray &fileContent);
    void errorOccured(const QString &error);

private slots:
    void onSocketReadyRead();
    void onSocketConnected();
    void onSocketDisconnected();
    void onSocketError(QAbstractSocket::SocketError socketError);
    void onSocketSslErrors(const QList<QSslError> &list);
    void onHttpMultiPartHandlerError();

private:
    quintptr mSocketDescriptor;
    QSslSocket *mSocket;
    HttpMultiPartHandler mHttpMultiPartHandler;
};

#endif // SSLSOCKETLISTENER_H
