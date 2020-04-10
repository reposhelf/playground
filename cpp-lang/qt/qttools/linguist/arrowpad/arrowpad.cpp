#include "arrowpad.h"

#include <QtWidgets>

ArrowPad::ArrowPad(QWidget *parent)
    :QWidget(parent)
{
    m_upButton = new QPushButton(tr("&Up"));
    m_downButton = new QPushButton(tr("&Down"));
    m_leftButton = new QPushButton(tr("&Left"));
    m_rightButton = new QPushButton(tr("&Right"));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(m_upButton, 0, 1);
    mainLayout->addWidget(m_leftButton, 1, 0);
    mainLayout->addWidget(m_rightButton, 1, 2);
    mainLayout->addWidget(m_downButton, 2, 1);
    setLayout(mainLayout);
}
