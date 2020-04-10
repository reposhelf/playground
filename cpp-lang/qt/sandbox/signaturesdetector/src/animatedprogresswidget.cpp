#include "animatedprogresswidget.h"

#include <QMovie>

const QSize AnimatedProgressWidget::s_scaledSize = QSize(30, 30);

AnimatedProgressWidget::AnimatedProgressWidget(QWidget *parent)
    : QLabel(parent),
      m_movie(new QMovie())
{
    setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    m_movie->setFileName(":/img/progress.gif");
    m_movie->setScaledSize(s_scaledSize);

    setMovie(m_movie);
}

/// Destructor.
AnimatedProgressWidget::~AnimatedProgressWidget()
{
    delete m_movie;
}

/**
 * This slot invokes when test instance starts for testing.
 */
void AnimatedProgressWidget::startProgress()
{
    setHidden(false);
    m_movie->start();
}

/**
 * This slot invokes when test instance stops for testing.
 */
void AnimatedProgressWidget::stopProgress()
{
    setHidden(true);
    m_movie->stop();
}
