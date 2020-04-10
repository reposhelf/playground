#include <QDebug>
#include <QTime>
#include <QDateTime>
#include <QFile>
#include <QFileInfo>
#include "tipdelegate.h"
#include "tipcontainer.h"

// constructor()

TipDelegate::TipDelegate()
    : m_container(new TipContainer)
{
    m_index = randomNumber();
}

// ~destructor()

TipDelegate::~TipDelegate()
{
    delete m_container;
}

// tipText()

QString TipDelegate::tipText() const
{
    QString textFilePath = m_container->tip(m_index).textFilePath();
    QFile file(textFilePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Cannot open file for reading"
                 << qPrintable(file.errorString());
        return QString();
    }
    QTextStream in(&file);
    return in.readAll();
}

// tipImagePath()

QString TipDelegate::tipImagePath() const
{
    QString imageFilePath;
    if ((imageFilePath = m_container->tip(m_index).imageFilePath()) != "None")
        return imageFilePath;
    return QString();
}

// tipImageName()

QString TipDelegate::tipImageName() const
{
    QString imageFileName;
    if ((imageFileName = m_container->tip(m_index).imageFilePath()) != "None") {
        QFileInfo fileInfo(imageFileName);
        return fileInfo.fileName();
    }
    return QString();
}

// nextTip()

void TipDelegate::nextTip()
{
    m_index < m_container->count() - 1 ? ++m_index : m_index = 0;
}

// previousTip()

void TipDelegate::previousTip()
{
    m_index > 0 ? --m_index : m_index = m_container->count() - 1;
}

// randomNumber()

int TipDelegate::randomNumber() const
{
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    return qrand() % m_container->count();
}
