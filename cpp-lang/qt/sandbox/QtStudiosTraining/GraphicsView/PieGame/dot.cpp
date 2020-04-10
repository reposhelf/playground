#include <QPainter>
#include <QDebug>

#include "dot.h"

Dot::Dot( QGraphicsItem *parent ) : QGraphicsItem( parent )
{
}

Dot::~Dot()
{
    qDebug() << "Destructor work!";
}

QRectF Dot::boundingRect() const
{
    return QRectF( 0, 0, 30, 30 );
}

void Dot::paint( QPainter *painter,
                 const QStyleOptionGraphicsItem *option,
                 QWidget *widget )
{
    if ( collidingItems().size() > 0 )
        m_eaten = true;

    if ( !m_eaten ) {
        painter->setBrush( Qt::white );
        painter->drawPixmap( 5, 5, 25, 25, QPixmap( ":images/pie.gif" ) );
    }
}

