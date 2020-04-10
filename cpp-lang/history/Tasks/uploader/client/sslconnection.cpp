#include "sslconnection.h"

#include <QHttpMultiPart>
#include <QFileInfo>
#include <QNetworkReply>


SslConnection::SslConnection(QObject *parent)
    : QObject(parent)
{
    makeConnections();
}

SslConnection::SslConnection(const QString &serverName, int serverPort, QObject *parent)
    : QObject(parent),
      mServerName(serverName),
      mServerPort(serverPort)
{
    makeConnections();
}

void SslConnection::setServerName(const QString &serverName)
{
    mServerName = serverName;
}

void SslConnection::setServerPort(int serverPort)
{
    mServerPort = serverPort;
}

SslConnection::SendingStatus SslConnection::sendFile(const QString &filePath)
{
    QHttpMultiPart *httpMultiPart = createHttpMultiPart(filePath);
    if (!httpMultiPart)
        return Fail;

    QNetworkReply *reply = mNetworkManager.post(makeNetworkRequest(), httpMultiPart);

    httpMultiPart->setParent(reply);

    connect(this, SIGNAL(uploadCanceled()), reply, SLOT(abort()));
    connect(reply, SIGNAL(finished()), reply, SLOT(deleteLater()));
    connect(reply, SIGNAL(finished()), this, SIGNAL(uploadFinished()));
    connect(reply, SIGNAL(uploadProgress(qint64,qint64)),
            this, SIGNAL(uploadProgress(qint64,qint64)));

    return mError == NoError ? Success : Fail;
}

QString SslConnection::errorString()
{
    QString ret = "SslConnection::NoError";
    switch (mError)
    {
    case NoError:
        break;
    case TransferFileOpeningError:
        ret = "SslConnection::TransferFileOpeningError";
        break;
    case SslCertificateOpeningError:
        ret = "SslConnection::SslCertificateOpeningError";
        break;
    default: ;
    }
    mError = NoError;
    return ret;
}

void SslConnection::onNetworkManagerSslErrors(QNetworkReply *reply, const QList<QSslError> &errors)
{
    Q_UNUSED(reply)

    foreach (auto i, errors)
        qDebug() << i.errorString();
}

void SslConnection::onNetworkManagerEncrypted(QNetworkReply *reply)
{
    Q_UNUSED(reply)

    qDebug() << Q_FUNC_INFO;
}

void SslConnection::onNetworkManagerFinished(QNetworkReply *reply)
{
    qDebug() << Q_FUNC_INFO;

    qDebug() << reply->errorString() << ": " << reply->error();

    reply->deleteLater();
}

QHttpMultiPart *SslConnection::createHttpMultiPart(const QString &filePath)
{
    QHttpMultiPart *httpMultiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    QHttpPart httpPart;
    httpPart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("any/file"));
    httpPart.setHeader(QNetworkRequest::ContentDispositionHeader,
                       QVariant("form-data; name=\"any\""));
    httpPart.setRawHeader("File-Name", getFileName(filePath).toUtf8());
    QFile *file = new QFile(filePath);
    if (!file->open(QIODevice::ReadOnly))
    {
        delete httpMultiPart;
        delete file;
        mError = TransferFileOpeningError;
        return nullptr;
    }
    httpPart.setBodyDevice(file);

    httpMultiPart->append(httpPart);

    file->setParent(httpMultiPart);

    return httpMultiPart;
}

QString SslConnection::getFileName(const QString &filePath) const
{
    QFileInfo fileInfo(filePath);

    return fileInfo.fileName();
}

QSslConfiguration SslConnection::makeSslConfiguration()
{
    QFile certificateFile(":/localhost.pem");
    if (!certificateFile.open(QIODevice::ReadOnly))
        mError = SslCertificateOpeningError;

    QList<QSslCertificate> caCertificates;
    caCertificates.append(QSslCertificate(&certificateFile));
    QSslConfiguration sslConfig;
    sslConfig.setCaCertificates(caCertificates);

    return sslConfig;
}

QUrl SslConnection::makeUrl() const
{
    QUrl url;
    url.setScheme("https");
    url.setHost(mServerName);
    url.setPort(mServerPort);
    return url;
}

QNetworkRequest SslConnection::makeNetworkRequest()
{
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setUrl(makeUrl());
    request.setSslConfiguration(makeSslConfiguration());
    return request;
}

void SslConnection::makeConnections() const
{
    connect(&mNetworkManager, SIGNAL(encrypted(QNetworkReply*)),
            this, SLOT(onNetworkManagerEncrypted(QNetworkReply*)));
    connect(&mNetworkManager, SIGNAL(sslErrors(QNetworkReply*,QList<QSslError>)),
            this, SLOT(onNetworkManagerSslErrors(QNetworkReply*,QList<QSslError>)));
    connect(&mNetworkManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(onNetworkManagerFinished(QNetworkReply*)));
}
