#include <QPainter>

#include "edge.h"
#include "node.h"


Edge::Edge(Node *sourceNode, Node *destNode)
{
    // Cannot click the edges:
    setAcceptedMouseButtons(0);
    m_source = sourceNode;
    m_dest = destNode;
    m_source->addEdge(this);
    m_dest->addEdge(this);
    adjust();
}

Node *Edge::sourceNode() const
{
    return m_source;
}

Node *Edge::destNode() const
{
    return m_dest;
}

void Edge::adjust()
{
    if (!m_source || !m_dest)
        return;

    // Maps the point (x, y) or rect (x, y, width, height), which is in item's
    // coordinate system, to this item's coordinate system, and returns an
    // object with x and y (and optionally width and height) properties
    // matching the mapped coordinate:
    QLineF line(mapFromItem(m_source, m_source->width() / 2, m_source->height()),
                mapFromItem(m_dest, m_dest->width() / 2, 0));
    qreal length = line.length();

    // Prepares the item for a geometry change. Call this function before
    // changing the bounding rect of an item to keep QGraphicsScene's
    // index up to date:
    prepareGeometryChange();

    m_sourcePoint = line.p1();
    m_destPoint = line.p2();
}

QRectF Edge::boundingRect() const
{
    if (!m_source || !m_dest)
        return QRectF();

    return QRectF(m_sourcePoint, QSizeF(m_destPoint.x() - m_sourcePoint.x(),
                                        m_destPoint.y() - m_sourcePoint.y()));
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (!m_source || !m_dest)
        return;

    QLineF line(m_sourcePoint, m_destPoint);
    // Compares the floating point value p1 and p2 and returns true
    // if they are considered equal, otherwise false:
    if (qFuzzyCompare(line.length(), qreal(0.)))
        return;

    painter->setPen(QPen(QColor(0, 150, 0), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawLine(line);
}
