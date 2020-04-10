#include "square.h"

Square::Square(QObject *parent)
    : BaseItem(parent),
      m_signFlag(SignNone)
{
    connect(this, SIGNAL(signFlagChanged(Square::SignFlags)),
            this, SLOT(onSigneTypeChanged(Square::SignFlags)));
}

void Square::setImageSource(const QString &imageSource)
{
    if (m_imageSource == imageSource)
        return;
    m_imageSource = imageSource;
    emit imageSourceChanged(m_imageSource);
}

void Square::setSignFlag(Square::SignFlags signFlag)
{
    if (m_signFlag == signFlag)
        return;
    m_signFlag = signFlag;
    emit signFlagChanged(m_signFlag);
}

void Square::onSigneTypeChanged(Square::SignFlags signFlag)
{
    switch (signFlag)
    {
    case SignNone:
        setImageSource("");
        break;
    case SignX:
        setImageSource("qrc:/images/x.png");
        break;
    case SignO:
        setImageSource("qrc:/images/o.png");
        break;
    case SignMask:
        break;
    default:
        break;
    }
}
