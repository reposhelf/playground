#ifndef WEBPAGEDOWNLOADER_H
#define WEBPAGEDOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>

class WebPageDownloader : public QObject
{
    Q_OBJECT

public:
    explicit WebPageDownloader(QObject *parent = nullptr);
    ~WebPageDownloader();
    void download(const QUrl &url);
    QByteArray downloadedData() const { return m_downloadedData; }

signals:
    void downloaded();

private slots:
    void fileDownloaded(QNetworkReply *networkReply);

private:
    QNetworkAccessManager m_networkAccessManager;
    QByteArray m_downloadedData;
};

#endif // WEBPAGEDOWNLOADER_H
