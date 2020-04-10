#include "pathstrokerenderer.h"

#include <QtWidgets>

PathStrokeRenderer::PathStrokeRenderer(bool smallScreen, QWidget *parent)
    : ArthurFrame(parent),
      m_wasAnimated(true),
      m_penWidth(1.0),
      m_pathMode(CurveMode),
      m_joinStyle(Qt::BevelJoin),
      m_capStyle(Qt::FlatCap),
      m_penStyle(Qt::SolidLine),
      m_smallScreen(smallScreen),
      m_mousePress(QPoint()),
      m_mouseDrag(false),
      m_pointCount(-1),
      m_pointSize(10),
      m_activePoint(-1),
      m_points(),
      m_vectors(),
      m_fingerPointMapping(),
      m_timer()
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setAttribute(Qt::WA_AcceptTouchEvents);
}

void PathStrokeRenderer::setRealPenWidth(qreal penWidth)
{
    m_penWidth = penWidth;
    update();
}

void PathStrokeRenderer::paint(QPainter *painter)
{
    if (m_points.isEmpty())
        initializePoints();

    painter->setRenderHint(QPainter::Antialiasing);

    QPalette pal = palette();
    painter->setPen(Qt::NoPen);

    // construct the path
    QPainterPath path;
    path.moveTo(m_points.at(0));

    if (m_pathMode == LineMode) {
        for (int i = 1; i < m_points.size(); ++i) {
            path.lineTo(m_points.at(i));
        }
    } else {
        int i = 1;
        while (i + 2 < m_points.size()) {
            path.cubicTo(m_points.at(i), m_points.at(i + 1), m_points.at(i + 2));
            i += 3;
        }
        while (i < m_points.size()) {
            path.lineTo(m_points.at(i));
            ++i;
        }
    }

    // draw the path
    QColor lg = Qt::red;

    // the custom pen
    if (m_penStyle == Qt::NoPen) {
        QPainterPathStroker stroker;
        stroker.setWidth(m_penWidth);
        stroker.setCapStyle(m_capStyle);
        stroker.setJoinStyle(m_joinStyle);

        QVector<qreal> dashes;
        qreal space = 4.0;
        dashes << 1 << space
               << 3 << space
               << 9 << space
               << 27 << space
               << 9 << space
               << 3 << space;
        stroker.setDashPattern(dashes);
        QPainterPath stroke = stroker.createStroke(path);
        painter->fillPath(stroke, lg);
    } else {
        QPen pen(lg, m_penWidth, m_penStyle, m_capStyle, m_joinStyle);
        painter->strokePath(path, pen);
    }

    // draw the control points
    painter->setPen(QColor(50, 100, 120, 200));
    painter->setBrush(QColor(200, 200, 210, 120));
    for (int i = 0; i < m_points.size(); ++i) {
        QPointF pos = m_points.at(i);
        painter->drawEllipse(QRectF(pos.x() - m_pointSize,
                                    pos.y() - m_pointSize,
                                    m_pointSize * 2,
                                    m_pointSize * 2));
    }
    painter->setPen(QPen(Qt::lightGray, 0, Qt::SolidLine));
    painter->setBrush(Qt::NoBrush);
    painter->drawPolyline(m_points);
}

void PathStrokeRenderer::mousePressEvent(QMouseEvent *event)
{
    if (!m_fingerPointMapping.isEmpty())
        return;
    setDescriptionEnabled(false);
    m_activePoint = -1;
    qreal distance = -1;
    for (int i = 0; i < m_points.size(); ++i) {
        qreal d = QLineF(event->pos(), m_points.at(i)).length();
        if ((distance < 0 && d < 8 * m_pointSize) || d < distance) {
            distance = d;
            m_activePoint = i;
        }
    }

    if (m_activePoint != -1) {
        m_wasAnimated = m_timer.isActive();
        setAnimated(false);
        mouseMoveEvent(event);
    }

    // If we're not running in small screen mode, always assume we're dragging
    m_mouseDrag = !m_smallScreen;
    m_mousePress = event->pos();
}

void PathStrokeRenderer::mouseMoveEvent(QMouseEvent *event)
{
    if (!m_fingerPointMapping.isEmpty())
        return;
    // If we've moved more then 25 pixels, assume user is dragging
    if (!m_mouseDrag && QPoint(m_mousePress - event->pos()).manhattanLength() > 25)
        m_mouseDrag = true;

    if (m_mouseDrag && m_activePoint >= 0 && m_activePoint < m_points.size()) {
        m_points[m_activePoint] = event->pos();
        update();
    }
}

void PathStrokeRenderer::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)

    if (!m_fingerPointMapping.isEmpty())
        return;
    m_activePoint = -1;
    setAnimated(m_wasAnimated);

    if (!m_mouseDrag && m_smallScreen)
        emit clicked();
}

void PathStrokeRenderer::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == m_timer.timerId())
        updatePoints();
}

bool PathStrokeRenderer::event(QEvent *e)
{
    bool touchBegin = false;
    switch (e->type()) {
    case QEvent::TouchBegin:
        touchBegin = true;
    case QEvent::TouchUpdate:
    {
        const QTouchEvent *const event = static_cast<const QTouchEvent*>(e);
        const QList<QTouchEvent::TouchPoint> points = event->touchPoints();
        foreach (const QTouchEvent::TouchPoint &touchPoint, points) {
            const int id = touchPoint.id();
            switch (touchPoint.state()) {
            case Qt::TouchPointPressed:
            {
                // find the point, move it
                QSet<int> activePoints = QSet<int>::fromList(m_fingerPointMapping.values());
                int activePoint = -1;
                qreal distance = -1;
                const int pointsCount = m_points.size();
                for (int i=0; i<pointsCount; ++i) {
                    if (activePoints.contains(i))
                        continue;

                    qreal d = QLineF(touchPoint.pos(), m_points.at(i)).length();
                    if ((distance < 0 && d < 12 * m_pointSize) || d < distance) {
                        distance = d;
                        activePoint = i;
                    }
                }
                if (activePoint != -1) {
                    m_fingerPointMapping.insert(touchPoint.id(), activePoint);
                    m_points[activePoint] = touchPoint.pos();
                }
                break;
            }
            case Qt::TouchPointReleased:
            {
                // move the point and release
                QHash<int,int>::iterator it = m_fingerPointMapping.find(id);
                m_points[it.value()] = touchPoint.pos();
                m_fingerPointMapping.erase(it);
                break;
            }
            case Qt::TouchPointMoved:
            {
                // move the point
                const int pointIdx = m_fingerPointMapping.value(id, -1);
                if (pointIdx >= 0)
                    m_points[pointIdx] = touchPoint.pos();
                break;
            }
            default:
                break;
            }
        }
        if (m_fingerPointMapping.isEmpty()) {
            e->ignore();
            return false;
        } else {
            if (touchBegin) {
                m_wasAnimated = m_timer.isActive();
                setAnimated(false);
            }
            update();
            return true;
        }
    }
        break;
    case QEvent::TouchEnd:
        if (m_fingerPointMapping.isEmpty()) {
            e->ignore();
            return false;
        }
        m_fingerPointMapping.clear();
        setAnimated(m_wasAnimated);
        return true;
        break;
    default:
        break;
    }
    return QWidget::event(e);
}

void PathStrokeRenderer::setPenWidth(int penWidth)
{
    m_penWidth = penWidth / 10.0;
    update();
}

void PathStrokeRenderer::setAnimated(bool animated)
{
    m_timer.stop();
    if (animated)
        m_timer.start(25, this);
}

void PathStrokeRenderer::setFlatCap()
{
    m_capStyle = Qt::FlatCap;
    update();
}

void PathStrokeRenderer::setSquareCap()
{
    m_capStyle = Qt::SquareCap;
    update();
}

void PathStrokeRenderer::setRoundCap()
{
    m_capStyle = Qt::RoundCap;
    update();
}

void PathStrokeRenderer::setBevelJoin()
{
    m_joinStyle = Qt::BevelJoin;
    update();
}

void PathStrokeRenderer::setMiterJoin()
{
    m_joinStyle = Qt::MiterJoin;
    update();
}

void PathStrokeRenderer::setRoundJoin()
{
    m_joinStyle = Qt::RoundJoin;
    update();
}

void PathStrokeRenderer::setCurveMode()
{
    m_pathMode = CurveMode;
    update();
}

void PathStrokeRenderer::setLineMode()
{
    m_pathMode = LineMode;
    update();
}

void PathStrokeRenderer::setSolidLine()
{
    m_penStyle = Qt::SolidLine;
    update();
}

void PathStrokeRenderer::setDashLine()
{
    m_penStyle = Qt::DashLine;
    update();
}

void PathStrokeRenderer::setDotLine()
{
    m_penStyle = Qt::DotLine;
    update();
}

void PathStrokeRenderer::setDashDotLine()
{
    m_penStyle = Qt::DashDotLine;
    update();
}

void PathStrokeRenderer::setDashDotDotLine()
{
    m_penStyle = Qt::DashDotDotLine;
    update();
}

void PathStrokeRenderer::setCustomDashLine()
{
    m_penStyle = Qt::NoPen;
    update();
}

void PathStrokeRenderer::initializePoints()
{
    const int count = 7;
    m_points.clear();
    m_vectors.clear();

    QMatrix m;
    qreal rot = 360.0 / count;
    QPointF center(width() / 2, height() / 2);
    QMatrix vm;
    vm.shear(2, -1);
    vm.scale(3, 3);

    for (int i = 0; i < count; ++i) {
        m_vectors << QPointF(.1f, .25f) * (m * vm);
        m_points << QPointF(0, 100) * m + center;
        m.rotate(rot);
    }
}

void PathStrokeRenderer::updatePoints()
{
    qreal pad = 10.0;
    qreal left = pad;
    qreal right = width() - pad;
    qreal top = pad;
    qreal bottom = height() - pad;

    Q_ASSERT(m_points.size() == m_vectors.size());
    for (int i = 0; i < m_points.size(); ++i) {
        QPointF pos = m_points.at(i);
        QPointF vec = m_vectors.at(i);
        pos += vec;
        if (pos.x() < left || pos.x() > right) {
            vec.setX(-vec.x());
            pos.setX(pos.x() < left ? left : right);
        }
        if (pos.y() < top || pos.y() > bottom) {
            vec.setY(-vec.y());
            pos.setY(pos.y() < top ? top : bottom);
        }
        m_points[i] = pos;
        m_vectors[i] = vec;
    }
    update();
}
