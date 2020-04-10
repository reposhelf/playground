#ifndef VISUALTREEWIDGET_H
#define VISUALTREEWIDGET_H

#include <QGraphicsView>

class Node;
class QGraphicsScene;

class VisualTreeWidget : public QGraphicsView
{
public:
    VisualTreeWidget(QWidget *parent = 0);

protected:
    void drawBackground(QPainter *painter, const QRectF &rect);

private:
    void setConnect(Node *sourceNode, Node *destNode);
    void fillListOfNodes(Node *node1, Node *node2);
    void setTreeLayout();
    void stretching(QList<Node *> nodes);

    Node *m_root;
    QGraphicsScene *m_scene;
    QList<Node *> m_nodes;
};
#endif // VISUALTREEWIDGET_H
