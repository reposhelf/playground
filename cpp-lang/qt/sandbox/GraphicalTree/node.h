#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>

class VisualTreeWidget;
class Edge;

class Node : public QGraphicsItem
{
public:
    Node(const QString& title, VisualTreeWidget *treeWidget);

    void addEdge(Edge *edge);
    QList<Edge *> edges() const;

    void setTop(qreal top);
    qreal top() const;

    qreal width() const;
    qreal height() const;

protected:
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

private:
    static const qreal m_width = 120;
    static const qreal m_height = 50;

    QList<Edge *> m_edgeList;
    QPointF m_newPos;
    VisualTreeWidget *m_treeWidget;
    QString m_title;
    qreal m_top;
};
#endif // NODE_H
