#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsItem>

int main( int argc, char *argv[] )
{
    QApplication app( argc, argv );
    QGraphicsView view;

    QGraphicsScene *scene = new QGraphicsScene( &view );
    scene->setBackgroundBrush( Qt::yellow );
    view.setScene( scene );

    QGraphicsRectItem *rect = new QGraphicsRectItem( 0, 0, 100, 100 );
    scene->addItem( rect );

    QGraphicsRectItem *rect2 = new QGraphicsRectItem( 0, 0, 100, 100 );
    scene->addItem( rect2 );

    QGraphicsTextItem *text = scene->addText( "Hello World!" );
    text->setFlag( QGraphicsItem::ItemIgnoresTransformations );

    rect2->setPos( rect2->x(), rect2->y()-10 );
    rect2->setRotation( 15 );
    rect2->setPos( rect2->x()+10, rect2->y() );
    view.scale( 0.5, 0.5 );

    view.resize( 400, 400 );
    view.show();

    return app.exec();
}
