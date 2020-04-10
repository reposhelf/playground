#ifndef CLABEL_H
#define CLABEL_H

#include "clabel_global.h"

#include <QLabel>

class CLABELSHARED_EXPORT CLabel : public QLabel
{
    Q_OBJECT

public:
    CLabel(QWidget *parent = Q_NULLPTR);
    CLabel(const QString &text, QWidget *parent = Q_NULLPTR);

    QString getText() const;

private:
    void setColor(const QColor &c);
};

#endif // CLABEL_H
