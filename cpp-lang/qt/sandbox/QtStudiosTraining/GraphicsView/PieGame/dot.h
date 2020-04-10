#ifndef DOT_H
#define DOT_H

#include <QGraphicsItem>

class Dot : public QGraphicsItem {

public:
    Dot( QGraphicsItem *parent = 0 );
    ~Dot();

protected:
    void paint( QPainter *painter,
                const QStyleOptionGraphicsItem *option,
                QWidget *widget );
    QRectF boundingRect() const;

private:
    bool m_eaten;
};

#endif // DOT_H
