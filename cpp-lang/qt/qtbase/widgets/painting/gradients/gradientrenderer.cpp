#include "gradientrenderer.h"
#include "hoverpoints.h"

GradientRenderer::GradientRenderer(QWidget *parent)
    : ArthurFrame(parent),
      m_stops(),
      m_hoverPoints(Q_NULLPTR),
      m_spread(QGradient::PadSpread),
      m_gradientType(Qt::LinearGradientPattern)
{
    m_hoverPoints = new HoverPoints(this, HoverPoints::CircleShape);
    m_hoverPoints->setPointSize(QSize(20, 20));
    m_hoverPoints->setConnectionType(HoverPoints::NoConnection);
    m_hoverPoints->setEditable(false);

    QVector<QPointF> points;
    points << QPointF(100.0, 100.0) << QPointF(200.0, 200.0);
    m_hoverPoints->setPoints(points);
}

void GradientRenderer::setGradientStops(const QGradientStops &stops)
{
    m_stops = stops;

    update();
}

void GradientRenderer::setPadSpread()
{
    m_spread = QGradient::PadSpread;

    update();
}

void GradientRenderer::setRepeatSpread()
{
    m_spread = QGradient::RepeatSpread;

    update();
}

void GradientRenderer::setReflectSpread()
{
    m_spread = QGradient::ReflectSpread;

    update();
}

void GradientRenderer::setLinearGradient()
{
    m_gradientType = Qt::LinearGradientPattern;

    update();
}

void GradientRenderer::setRadialGradient()
{
    m_gradientType = Qt::RadialGradientPattern;

    update();
}

void GradientRenderer::setConicalGradient()
{
    m_gradientType = Qt::ConicalGradientPattern;

    update();
}

void GradientRenderer::paint(QPainter *painter)
{
    QPolygonF points = m_hoverPoints->points();

    QGradient gradient;

    if (m_gradientType == Qt::LinearGradientPattern) {
        gradient = QLinearGradient(points.at(0), points.at(1));
    } else if (m_gradientType == Qt::RadialGradientPattern) {
        gradient = QRadialGradient(points.at(0), qMin(width(), height()) / 3.0, points.at(1));
    } else {
        QLineF line(points.at(0), points.at(1));
        qreal angle = line.angle(QLineF(0.0, 0.0, 1.0, 0.0));
        if (line.dy() > 0)
            angle = 360 - angle;
        gradient = QConicalGradient(points.at(0), angle);
    }

    for (int i = 0; i < m_stops.size(); ++i)
        gradient.setColorAt(m_stops.at(i).first, m_stops.at(i).second);

    gradient.setSpread(m_spread);

    painter->setBrush(gradient);
    painter->setPen(Qt::NoPen);
    painter->drawRect(rect());
}

void GradientRenderer::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event)

    setDescriptionEnabled(false);
}
