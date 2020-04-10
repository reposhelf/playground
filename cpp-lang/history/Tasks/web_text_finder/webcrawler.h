#ifndef WEBCRAWLER_H
#define WEBCRAWLER_H

#include "webpagedownloader.h"

#include <QThread>

class WebCrawler : public QThread
{
    Q_OBJECT

public:
    WebCrawler();
    ~WebCrawler();
    void run();

signals:
    void currentProcessFinished(QString, QString);
    void finished();

private slots:
    void startDownload();
    void webPageDownloaded();

private:
    void grabLink();
    QStringList getLinks() const;
    QString getStatus() const;

    WebPageDownloader m_webPageDownloader;
    QString m_link;
};

#endif // WEBCRAWLER_H
