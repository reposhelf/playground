#include "ball.h"
#include <QDebug>

Ball::Ball( QGraphicsScene *scene, QObject *object, QGraphicsEllipseItem *parent )
    : QObject( object ), QGraphicsEllipseItem( parent ), m_scene( scene )
{
    setRect( QRectF( 0, 0, m_diameter, m_diameter ) );
    setPen( QPen( Qt::black ) );
    setBrush( QBrush( Qt::red ) );
    setFlags( QGraphicsItem::ItemIsMovable );

    m_topLimit = 0;
    m_bottomLimit = scene->height() - m_diameter;
    m_hgt = scene->height() - y();
    m_direction = DOWN;

    m_timer = new QTimer( this );
    connect( m_timer, SIGNAL(timeout()), this, SLOT(move()) );
    m_timer->start( m_interval );
}

Ball::~Ball()
{
    delete m_timer;
}

void Ball::move()
{
    switch ( m_direction ) {
    case UP:
        if ( y() != m_topLimit )
            setPos( QPoint(x(), y()-m_step) );
        else {
            m_direction = DOWN;
            m_timer->setInterval( m_interval );
        }
        break;
    case DOWN:
        if ( y() != m_bottomLimit )
            setPos( QPoint(x(), y()+m_step) );
        else {
            m_direction = UP;
            m_timer->setInterval( m_interval );
            bounce();
        }
        break;
    }
}

void Ball::mousePressEvent( QGraphicsSceneMouseEvent *e )
{
    m_timer->stop();
    QGraphicsItem::mousePressEvent( e );
}

void Ball::mouseReleaseEvent( QGraphicsSceneMouseEvent *e )
{
    m_direction = DOWN;
    m_hgt = m_scene->height() - m_diameter - y();
    m_timer->start();
    QGraphicsItem::mouseReleaseEvent( e );
}

void Ball::bounce()
{
    m_topLimit = m_scene->height() - m_diameter - (m_hgt * m_bounceKoef);
    m_hgt *= m_bounceKoef;
}
