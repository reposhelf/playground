#ifndef SUPERITEM_H
#define SUPERITEM_H

#include <QGraphicsItem>

class SuperItem : public QGraphicsItem {

public:
    SuperItem( QGraphicsItem *parent = 0 );

protected:
    void paint( QPainter *painter,
                const QStyleOptionGraphicsItem *option,
                QWidget *widget );
    QRectF boundingRect() const;

    virtual void keyPressEvent( QKeyEvent *event );

private:
    int m_rotation;
};

#endif // SUPERITEM_H
