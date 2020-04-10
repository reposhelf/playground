#include "lcdnumber.h"

class LcdNumberPrivate : public QFramePrivate
{
public:
    void init();
    void internalSetString(const QString &s);
    void drawString(const QString &s, QPainter &, QBitArray * = 0, bool = true);
    void drawDigit(const QPoint &, QPainter &, int, char, char = ' ');
    void drawSegment(const QPoint &, char, QPainter &, int, bool = false);

    int ndigits;
    double val;
    uint base : 2;
    uint smallPoint : 1;
    uint fill : 1;
    uint shadow : 1;
    QString digitStr;
    QBitArray points;
};

LcdNumber::LcdNumber(QWidget *parent)
    : QFrame(parent)
{
}

LcdNumber::LcdNumber(uint numDigits, QWidget *parent)
    : QFrame(parent)
{
}

LcdNumber::~LcdNumber()
{
}

void LcdNumber::display(int num)
{
}

void LcdNumber::display(double num)
{
}

void LcdNumber::setHexMode()
{
}

void LcdNumber::setDecMode()
{
}

void LcdNumber::setOctMode()
{
}

void LcdNumber::setBinMode()
{
}

void LcdNumber::setSmallDecimalPoint(bool point)
{
}
