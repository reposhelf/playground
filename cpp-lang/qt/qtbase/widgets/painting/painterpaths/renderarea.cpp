#include "renderarea.h"

#include <QPainter>

RenderArea::RenderArea(const QPainterPath &path, QWidget *parent)
    : QWidget(parent),
      m_path(path),
      m_fillColor1(),
      m_fillColor2(),
      m_penWidth(1),
      m_penColor(),
      m_degree(0)
{
    setBackgroundRole(QPalette::Base);
}

RenderArea::~RenderArea()
{
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize RenderArea::sizeHint() const
{
    return QSize(100, 100);
}

void RenderArea::setPenWidth(int width)
{
    m_penWidth = width;
    update();
}

void RenderArea::setRotationAngle(int degree)
{
    m_degree = degree;
    update();
}

void RenderArea::setFillRule(Qt::FillRule rule)
{
    m_path.setFillRule(rule);
    update();
}

void RenderArea::setFillGradient(const QColor &color1, const QColor &color2)
{
    m_fillColor1 = color1;
    m_fillColor2 = color2;
    update();
}

void RenderArea::setPenColor(const QColor &color)
{
    m_penColor = color;
    update();
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.scale(width() / 100.0, height() / 100.0);
    painter.translate(50.0, 50.0);
    painter.rotate(-m_degree);
    painter.translate(-50.0, -50.0);
    painter.setPen(QPen(m_penColor, m_penWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    QLinearGradient gradient(0, 0, 0, 100);
    gradient.setColorAt(0.0, m_fillColor1);
    gradient.setColorAt(1.0, m_fillColor2);
    painter.setBrush(gradient);
    painter.drawPath(m_path);
}
