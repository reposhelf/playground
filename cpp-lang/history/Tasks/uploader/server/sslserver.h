#ifndef SSLSERVER_H
#define SSLSERVER_H

#include <QTcpServer>

class SslServer : public QTcpServer
{
    Q_OBJECT
public:
    SslServer(quint16 port, const QString &dirToSave, QObject *parent = Q_NULLPTR);
    ~SslServer() = default;

    void startServer();

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    void saveFile(const QString &fileName, const QByteArray &fileContent);
    void onSslListenerErrorOccured(const QString &error);

private:
    quint16 mPort;
    QString mDirToSave;
};

#endif // SSLSERVER_H
