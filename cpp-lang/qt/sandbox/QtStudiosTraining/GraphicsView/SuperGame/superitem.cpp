#include "superitem.h"
#include <QPainter>
#include <QKeyEvent>

SuperItem::SuperItem( QGraphicsItem *parent ) : QGraphicsItem( parent )
{
    setFlag( QGraphicsItem::ItemIsFocusable );
}

QRectF SuperItem::boundingRect() const
{
    return QRectF( 0, 0, 30, 30 );
}

void SuperItem::paint( QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget )
{
    painter->setBrush( Qt::yellow );
    painter->drawRoundedRect( 0, 0, 30, 30, 5, 5 );
}

void SuperItem::keyPressEvent( QKeyEvent *event )
{
    switch ( event->key() ) {
    case Qt::Key_Right: {
            moveBy( 30, 0 );
            break;
        }
    case Qt::Key_Left: {
            moveBy( -30, 0 );
            break;
        }
    case Qt::Key_Up: {
            moveBy( 0, -30 );
            break;
        }
    case Qt::Key_Down: {
            moveBy( 0, 30 );
            break;
        }
    }

    update();
}
