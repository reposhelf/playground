#include "circlewidget.h"

#include <QtWidgets>

CircleWidget::CircleWidget(QWidget *parent)
    : QWidget(parent),
      m_floatBased(false),
      m_antialised(false),
      m_frameNo(0)
{
    setBackgroundRole(QPalette::Base);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void CircleWidget::setFloatBased(bool floatBased)
{
    m_floatBased = floatBased;
    update();
}

void CircleWidget::setAntialised(bool antialised)
{
    m_antialised = antialised;
    update();
}

QSize CircleWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize CircleWidget::sizeHint() const
{
    return QSize(180, 180);
}

void CircleWidget::nextAnimationFrame()
{
    ++m_frameNo;
    update();
}

void CircleWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, m_antialised);
    painter.translate(width() / 2, height() / 2);

    for (int diameter = 0; diameter < 256; diameter += 9) {
        int delta = abs((m_frameNo % 128) - diameter / 2);
        int alpha = 255 - (delta * delta) / 4 - diameter;

        if (alpha > 0) {
            painter.setPen(QPen(QColor(0, diameter / 2, 127, alpha), 3));

            if (m_floatBased)
                painter.drawEllipse(QRectF(-diameter / 2.0, -diameter / 2.0, diameter, diameter));
            else
                painter.drawEllipse(QRect(-diameter / 2, -diameter / 2, diameter, diameter));
        }
    }
}
