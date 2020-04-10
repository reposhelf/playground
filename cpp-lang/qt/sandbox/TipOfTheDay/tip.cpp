#include "tip.h"

// constructor()

Tip::Tip()
{
}

// constructor()

Tip::Tip(QString textFilePath, QString imageFilePath)
    : m_textFilePath(textFilePath), m_imageFilePath(imageFilePath)
{
}

// textFilePath()

QString Tip::textFilePath() const
{
    return m_textFilePath;
}

// imageFilePath()

QString Tip::imageFilePath() const
{
    return m_imageFilePath;
}
