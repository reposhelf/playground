#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QLabel;
class CircleWidget;
class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = Q_NULLPTR);

private:
    QLabel *createLabel(const QString &text) const;

    QLabel *m_alisedLabel;
    QLabel *m_antialisedLabel;
    QLabel *m_intLabel;
    QLabel *m_floatLabel;

    CircleWidget *m_circleWidgets[2][2];
};

#endif // WINDOW_H
