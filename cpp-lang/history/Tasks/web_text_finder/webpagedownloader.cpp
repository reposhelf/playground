#include "webpagedownloader.h"

#include <QNetworkReply>

WebPageDownloader::WebPageDownloader(QObject *parent)
    : QObject(parent)
{
    connect(&m_networkAccessManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(fileDownloaded(QNetworkReply*)));
}

WebPageDownloader::~WebPageDownloader()
{

}

void WebPageDownloader::download(const QUrl &url)
{
    QNetworkRequest request(url);
    m_networkAccessManager.get(request);
}

void WebPageDownloader::fileDownloaded(QNetworkReply *networkReply)
{
    m_downloadedData = networkReply->readAll();
    networkReply->deleteLater();
    emit downloaded();
}
