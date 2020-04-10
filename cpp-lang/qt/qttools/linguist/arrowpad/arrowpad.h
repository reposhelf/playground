#ifndef ARROWPAD_H
#define ARROWPAD_H

#include <QWidget>

class QPushButton;

class ArrowPad : public QWidget
{
    Q_OBJECT

public:
    ArrowPad(QWidget *parent = Q_NULLPTR);

private:
    QPushButton *m_upButton;
    QPushButton *m_downButton;
    QPushButton *m_leftButton;
    QPushButton *m_rightButton;
};

#endif // ARROWPAD_H
