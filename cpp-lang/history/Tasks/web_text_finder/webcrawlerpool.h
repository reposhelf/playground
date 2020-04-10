#ifndef WEBCRAWLERPOOL_H
#define WEBCRAWLERPOOL_H

#include <QObject>
#include <QVector>

class WebCrawler;
class WebCrawlerPool : public QObject
{
    Q_OBJECT

public:
    explicit WebCrawlerPool(QObject *parent = nullptr);
    ~WebCrawlerPool();

    void start();
    void stop();
    void pause();

    void setSize(int size);
    int size() const { return m_maxThreads; }

    void setMaxLinksAmount(int maxLinksAmount);
    int maxLinksAmount() const { return m_maxLinksAmount; }

    void setStartUrl(const QString &url);
    QString startUrl() const { return m_startUrl; }

    void setTextForSearch(const QString &textForSearch);
    QString textForSearch() const { return m_textForSearch; }

signals:
    void progressChanged(int progress);
    void statusInformationUpdated(QString, QString);

private slots:
    void onWebCrawlerFinished();

private:
    void initPool();

    QVector<WebCrawler *> m_webCrawlers;
    QString m_startUrl;
    QString m_textForSearch;
    int m_maxThreads;
    int m_maxLinksAmount;
};

#endif // WEBCRAWLERPOOL_H
