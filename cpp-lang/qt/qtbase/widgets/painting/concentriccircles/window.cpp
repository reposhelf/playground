#include "window.h"
#include "circlewidget.h"

#include <QtWidgets>

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    m_alisedLabel = createLabel(tr("Alised"));
    m_antialisedLabel = createLabel(tr("Antialised"));
    m_intLabel = createLabel(tr("Int"));
    m_floatLabel = createLabel(tr("Float"));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(m_alisedLabel, 0, 1);
    layout->addWidget(m_antialisedLabel, 0, 2);
    layout->addWidget(m_intLabel, 1, 0);
    layout->addWidget(m_floatLabel, 2, 0);

    QTimer *timer = new QTimer(this);

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            m_circleWidgets[i][j] = new CircleWidget;
            m_circleWidgets[i][j]->setAntialised(j != 0);
            m_circleWidgets[i][j]->setFloatBased(i != 0);

            connect(timer, SIGNAL(timeout()), m_circleWidgets[i][j], SLOT(nextAnimationFrame()));

            layout->addWidget(m_circleWidgets[i][j], i + 1, j + 1);
        }
    }

    timer->start(10);
    setLayout(layout);
    setWindowTitle(tr("Concentric Circles"));
}

QLabel *Window::createLabel(const QString &text) const
{
    QLabel *label = new QLabel(text);
    label->setAlignment(Qt::AlignCenter);
    label->setMargin(2);
    label->setFrameStyle(QFrame::Box | QFrame::Sunken);
    return label;
}
