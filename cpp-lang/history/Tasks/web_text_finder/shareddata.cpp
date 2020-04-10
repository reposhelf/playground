#include "shareddata.h"

SharedData *SharedData::instance()
{
    static SharedData sharedData;
    return &sharedData;
}

void SharedData::putLink(const QString &link)
{
    if (m_visitCount < m_maxVisitCount) {
        m_linksQueue.enqueue(link);
        ++m_visitCount;
    }
}

void SharedData::setVisitCount(int visitCount)
{
    m_visitCount = visitCount;
}

void SharedData::setMaxVisitCount(int maxVisitCount)
{
    m_maxVisitCount = maxVisitCount;
}
