#include <QPainter>
#include <QGraphicsSceneMouseEvent>

#include "node.h"
#include "visualtreewidget.h"
#include "edge.h"

Node::Node(const QString& title, VisualTreeWidget *treeWidget)
    : m_treeWidget(treeWidget)
{
    setFlag(ItemIsMovable);
    // To enable itemChange() notifications for position changes:
    setFlag(ItemSendsGeometryChanges);
    // To ensure that the nodes are always stacked on top of edges:
    setZValue(-1);

    // Testing:
    m_title = title;
    setAcceptHoverEvents(true);
    m_top = 0;
}

void Node::addEdge(Edge *edge)
{
    m_edgeList << edge;
    edge->adjust();
}

void Node::setTop(qreal top)
{
    m_top = top;
}

qreal Node::top() const
{
    return m_top;
}

QList<Edge *> Node::edges() const
{
    return m_edgeList;
}

qreal Node::width() const
{
    return m_width;
}

qreal Node::height() const
{
    return m_height;
}

QRectF Node::boundingRect() const
{
    return QRectF(0, 0, m_width, m_height);
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QLinearGradient gradient(0, 0, m_width, m_height);
    gradient.setColorAt(0, QColor(150, 150, 150));
    gradient.setColorAt(1, QColor(32, 127, 240));
    painter->setPen(Qt::NoPen);
//    painter->setBrush(QColor(80, 170, 240));
    painter->setBrush(gradient);
    painter->drawRoundRect(0, 0, m_width, m_height);

    if (m_title != "") {
        painter->setPen(QPen(Qt::black, 0));
        painter->setFont(QFont("Times", 11));
        painter->drawText(QRectF(5, 5, m_width-5, m_height-5), Qt::AlignCenter, m_title);
    }
}

void Node::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setCursor(Qt::OpenHandCursor);
}

void Node::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::ClosedHandCursor);
    QGraphicsItem::mousePressEvent(event);
}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::OpenHandCursor);
    QGraphicsItem::mouseReleaseEvent(event);
}

QVariant Node::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        foreach (Edge *edge, m_edgeList)
            edge->adjust();
        break;
    default:
        break;
    }

    return QGraphicsItem::itemChange(change, value);
}
