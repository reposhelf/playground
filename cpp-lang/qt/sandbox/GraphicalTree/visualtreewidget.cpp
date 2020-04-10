#include <QGraphicsScene>

#include "visualtreewidget.h"
#include "node.h"
#include "edge.h"


VisualTreeWidget::VisualTreeWidget(QWidget *parent)
    : QGraphicsView(parent)
{
    m_scene = new QGraphicsScene(this);
    // Next approach is ideal for dynamic scenes, where many items are added,
    // moved or removed continously:
    m_scene->setItemIndexMethod( QGraphicsScene::NoIndex );
    m_scene->setSceneRect(-700, -10, 1400, 800);
    setScene(m_scene);
    // Indicates that the engine should antialias edges of primitives if possible:
    setRenderHint(QPainter::Antialiasing);
    scale(qreal(0.8), qreal(0.8));

    m_root = new Node("CEO",this);
    Node *node1 = new Node("Vice President\nOperations", this);
    Node *node2 = new Node("Vice President\nSales & Marketing", this);
    Node *node3 = new Node("Director\n Accounting", this);
    Node *node4 = new Node("Director\n Manufacturing", this);
    Node *node5 = new Node("Director\n Marketing", this);
    Node *node6 = new Node("Director\n Eastern Region", this);
    Node *node7 = new Node("Director\n Western Region", this);
    Node *node8 = new Node("Manager\n Payroll", this);
    Node *node9 = new Node("Controller", this);
    Node *node10 = new Node("Manager\n Software", this);
    Node *node11 = new Node("Manager\n Hardware", this);
    Node *node12 = new Node("Manager\n Advertising", this);
    Node *node13 = new Node("Manager\n Packaging", this);
    Node *node14 = new Node("Manager\n Software", this);
    Node *node15 = new Node("Manager\n Hardware", this);
    Node *node16 = new Node("Manager\n Software", this);
    Node *node17 = new Node("Manager\n Hardware", this);
    setConnect(m_root, node1);
    setConnect(m_root, node2);
    setConnect(node1, node3);
    setConnect(node1, node4);
    setConnect(node2, node5);
    setConnect(node2, node6);
    setConnect(node2, node7);
    setConnect(node3, node8);
    setConnect(node3, node9);
    setConnect(node4, node10);
    setConnect(node4, node11);
    setConnect(node5, node12);
    setConnect(node5, node13);
    setConnect(node6, node14);
    setConnect(node6, node15);
    setConnect(node7, node16);
    setConnect(node7, node17);

    setTreeLayout();
}

void VisualTreeWidget::drawBackground(QPainter *painter, const QRectF &rect)
{
    QRectF sceneRect = this->sceneRect();
    painter->fillRect(sceneRect, QColor(45, 45, 45));
}

void VisualTreeWidget::setConnect(Node *sourceNode, Node *destNode)
{
    m_scene->addItem(sourceNode);
    m_scene->addItem(destNode);
    m_scene->addItem(new Edge(sourceNode, destNode));

    qreal newTop = sourceNode->top() + m_root->height() * 2;
    destNode->setTop(newTop);

    sourceNode->setPos(0 - m_root->width()/2, sourceNode->top());
    destNode->setPos(0 - m_root->width()/2, destNode->top());

    fillListOfNodes(sourceNode, destNode);
}

void VisualTreeWidget::fillListOfNodes(Node *node1, Node *node2)
{
    if (!m_nodes.contains(node1))
        m_nodes << node1;
    if (!m_nodes.contains(node2))
        m_nodes << node2;
}

void VisualTreeWidget::setTreeLayout()
{
    qreal top = m_root->top();
    for (int i = 0; i < m_nodes.length(); i++) {
        QList<Node *> nodes;
        for (int j = 0; j < m_nodes.length(); j++ ) {
            if (m_nodes[j]->top() == top)
                nodes << m_nodes[j];
        }
        stretching(nodes);
        top += m_root->height() * 2;
    }
}

void VisualTreeWidget::stretching(QList<Node *> nodes)
{
    qreal segment = m_scene->width() / nodes.length();
    qreal left = (segment - m_root->width()) / 2;
    qreal sceneLeft = -700;
    for (int k = 0; k < nodes.length(); k++)
        nodes[k]->setPos(sceneLeft + left + segment * k, nodes[k]->top());
}
