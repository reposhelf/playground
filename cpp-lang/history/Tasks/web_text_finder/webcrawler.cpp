#include "webcrawler.h"
#include "inputdata.h"
#include "shareddata.h"

#include <QMutex>
#include <QRegularExpressionMatchIterator>
#include <QDebug>

static QMutex queueMutex;

WebCrawler::WebCrawler()
{
    connect(this, SIGNAL(started()), this, SLOT(startDownload()));
    connect(&m_webPageDownloader, SIGNAL(downloaded()), this, SLOT(webPageDownloaded()));
}

WebCrawler::~WebCrawler()
{

}

void WebCrawler::run()
{

}

void WebCrawler::startDownload()
{
    grabLink();
    QUrl url(m_link);

    if (!url.isValid()) {
        qDebug() << Q_FUNC_INFO << "\nInvalid link";
        return;
    }

    m_webPageDownloader.download(url);
}

void WebCrawler::webPageDownloaded()
{
    QString status = getStatus();
    emit currentProcessFinished(m_link, status);

    QStringList links = getLinks();

    QMutexLocker locker(&queueMutex);
    foreach (QString s, links)
        SharedData::instance()->putLink(s);

    emit finished();
}

void WebCrawler::grabLink()
{
    QMutexLocker locker(&queueMutex);

    if (SharedData::instance()->hasLink())
        m_link = SharedData::instance()->popLink();
    else
        m_link.clear();
}

QStringList WebCrawler::getLinks() const
{
    const QString pattern = "https?://(www.)?[-a-z0-9_.]{2,}.[a-z]{2,6}((/[-а-яa-z0-9_]/|"
                            "[-а-яa-z0-9_]{2,}.(|[a-z]{2,6}))|(/[-а-яa-z0-9_]/[-а-яa-z0-9_]"
                            "{2,}.(|[a-z]{2,6})))[-a-zA-Z0-9@:%_+.~#?&//=]*";
    QRegularExpression regularExpression(pattern);
    QString dataStr(m_webPageDownloader.downloadedData());
    QRegularExpressionMatchIterator i = regularExpression.globalMatch(dataStr);

    QStringList links;
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        links << match.captured();
    }
    return links;
}

QString WebCrawler::getStatus() const
{
    QString dataStr(m_webPageDownloader.downloadedData());
    if (dataStr.contains(InputData::instance()->textForSearch()))
        return "Found";
    return "Not Found";
}
