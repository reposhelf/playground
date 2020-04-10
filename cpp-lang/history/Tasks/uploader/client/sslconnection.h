#ifndef SSLCONNECTION_H
#define SSLCONNECTION_H

#include <QObject>
#include <QSslConfiguration>
#include <QNetworkAccessManager>

class QHttpMultiPart;
class SslConnection : public QObject
{
    Q_OBJECT
public:
    enum SendingStatus {Success, Fail};
    enum Error {NoError, TransferFileOpeningError, SslCertificateOpeningError};

    explicit SslConnection(QObject *parent = nullptr);
    SslConnection(const QString &serverName, int serverPort, QObject *parent = nullptr);

    void setServerName(const QString &serverName);
    const QString &servername() const { return mServerName; }

    void setServerPort(int serverPort);
    int serverPort() const { return mServerPort; }

    SendingStatus sendFile(const QString &filePath);
    QString errorString();

signals:
    void uploadProgress(qint64 bytesSent, qint64 bytesTotal);
    void uploadFinished();
    void uploadCanceled();

private slots:
    void onNetworkManagerSslErrors(QNetworkReply *reply, const QList<QSslError> &errors);
    void onNetworkManagerEncrypted(QNetworkReply *reply);
    void onNetworkManagerFinished(QNetworkReply *reply);

private:
    QHttpMultiPart *createHttpMultiPart(const QString &filePath);
    QString getFileName(const QString &filePath) const;
    QSslConfiguration makeSslConfiguration();
    QUrl makeUrl() const;
    QNetworkRequest makeNetworkRequest();
    void makeConnections() const;

private:
    QNetworkAccessManager mNetworkManager;
    QString mServerName;
    int mServerPort = 0;
    Error mError = NoError;
};

#endif // SSLCONNECTION_H
