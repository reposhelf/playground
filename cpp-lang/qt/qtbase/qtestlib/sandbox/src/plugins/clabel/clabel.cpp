#include "clabel.h"

CLabel::CLabel(QWidget *parent)
    : QLabel(parent)
{
    setColor(QColor(Qt::yellow));
}

CLabel::CLabel(const QString &text, QWidget *parent)
    : QLabel(text, parent)
{
    setColor(QColor(Qt::yellow));
}

QString CLabel::getText() const
{
    return text();
}

void CLabel::setColor(const QColor &c)
{
    setAutoFillBackground(true);
    QPalette p = palette();
    p.setColor(QPalette::Window, c);
    setPalette(p);
}
