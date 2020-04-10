#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

#include "ball.h"

int main( int argc, char *argv[] )
{
    QApplication app( argc, argv );

    QGraphicsScene scene( QRectF( 0, 0, 400, 400 ) );
    scene.setBackgroundBrush( QBrush( Qt::black ) );

    QGraphicsView view( &scene );

    Ball *p_ball = new Ball( &scene );
    p_ball->setPos( QPoint( 175, 0 ) );

    scene.addItem( p_ball );

    view.show();

    return app.exec();
}
