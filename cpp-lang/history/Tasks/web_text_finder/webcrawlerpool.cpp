#include "webcrawlerpool.h"
#include "webcrawler.h"
#include "inputdata.h"
#include "shareddata.h"

WebCrawlerPool::WebCrawlerPool(QObject *parent)
    : QObject(parent)
{

}

WebCrawlerPool::~WebCrawlerPool()
{
    for (auto webCrawler : m_webCrawlers)
        delete webCrawler;
    m_webCrawlers.clear();
}

void WebCrawlerPool::start()
{
    QString startLink = InputData::instance()->startUrl();
    int maxLinks = InputData::instance()->maxLinks();

    SharedData::instance()->setVisitCount(0);
    SharedData::instance()->setMaxVisitCount(maxLinks);
    SharedData::instance()->putLink(startLink);

    for (auto i : m_webCrawlers)
        i->start();
}

void WebCrawlerPool::stop()
{
    // TODO
}

void WebCrawlerPool::pause()
{
    // TODO
}

void WebCrawlerPool::setSize(int size)
{
    m_maxThreads = size;

    initPool();
}

void WebCrawlerPool::setMaxLinksAmount(int maxLinksAmount)
{
    m_maxLinksAmount = maxLinksAmount;
}

void WebCrawlerPool::setStartUrl(const QString &url)
{
    m_startUrl = url;
}

void WebCrawlerPool::setTextForSearch(const QString &textForSearch)
{
    m_textForSearch = textForSearch;
}

void WebCrawlerPool::onWebCrawlerFinished()
{
    // update progress value
    int countOfVisitedLinks = SharedData::instance()->visitCount();
    int countOfMaxVisitedLinks = SharedData::instance()->maxVisitCount();
    int progress = countOfVisitedLinks * 100 / countOfMaxVisitedLinks;
    emit progressChanged(progress);

    // restart web crawler if needed
    WebCrawler *webCrawler = qobject_cast<WebCrawler *>(sender());
    if (!webCrawler)
        return;

    if (SharedData::instance()->hasLink())
        webCrawler->start();
}

void WebCrawlerPool::initPool()
{
    for (int i = 0; i < m_maxThreads; ++i) {
        WebCrawler *webCrawler = new WebCrawler();
        connect(webCrawler, SIGNAL(currentProcessFinished(QString,QString)),
                this, SIGNAL(statusInformationUpdated(QString,QString)), Qt::QueuedConnection);
        connect(webCrawler, SIGNAL(finished()), this, SLOT(onWebCrawlerFinished()),
                Qt::QueuedConnection);
        m_webCrawlers.append(webCrawler);
    }
}
