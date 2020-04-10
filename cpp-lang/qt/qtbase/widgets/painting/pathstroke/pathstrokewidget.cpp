#include "pathstrokewidget.h"
#include "pathstrokerenderer.h"
#include "pathstrokecontrols.h"

#include <QtWidgets>

PathStrokeWidget::PathStrokeWidget(bool smallScreen, QWidget *parent)
    : QWidget(parent),
      m_renderer(new PathStrokeRenderer(smallScreen, this)),
      m_controls(new PathStrokeControls(m_renderer, smallScreen, this))

{
    setWindowTitle(tr("Path Stroking"));

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(m_renderer);
    mainLayout->addWidget(m_controls);
}
