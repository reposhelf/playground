#ifndef SHAREDDATA_H
#define SHAREDDATA_H

#include <QString>
#include <QQueue>

class SharedData
{
public:
    SharedData(const SharedData&) = delete;
    SharedData &operator=(const SharedData&) = delete;
    static SharedData *instance();

    QString popLink() { return m_linksQueue.dequeue(); }
    void putLink(const QString &link);
    bool hasLink() const { return !m_linksQueue.isEmpty(); }

    void setVisitCount(int visitCount);
    int visitCount() const { return m_visitCount; }

    void setMaxVisitCount(int maxVisitCount);
    int maxVisitCount() const { return m_maxVisitCount; }

private:
    SharedData() = default;
    QQueue<QString> m_linksQueue;
    int m_maxVisitCount;
    int m_visitCount = 0;
};

#endif // SHAREDDATA_H
