#ifndef LCDNUMBER_H
#define LCDNUMBER_H

#include <QFrame>

class LcdNumberPrivate;
class LcdNumber : public QFrame
{
    Q_OBJECT

public:
    explicit LcdNumber(QWidget *parent = Q_NULLPTR);
    explicit LcdNumber(uint numDigits, QWidget *parent = Q_NULLPTR);
    ~LcdNumber();

signals:
    void overflow();

public slots:
    void display(int num);
    void display(double num);
    void display(const QString &str);
    void setHexMode();
    void setDecMode();
    void setOctMode();
    void setBinMode();
    void setSmallDecimalPoint(bool point);
};

#endif // LCDNUMBER_H
