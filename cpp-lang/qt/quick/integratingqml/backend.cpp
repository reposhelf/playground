#include <QDebug>

#include "backend.h"

BackEnd::BackEnd(QObject *parent)
    : QObject(parent)
{
}

void BackEnd::setUserName(const QString &userName)
{
    qDebug() << Q_FUNC_INFO << ":" << userName;

    if (userName == m_userName)
        return;

    m_userName = userName;
    emit userNameChanged();
}
