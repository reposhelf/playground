#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "superitem.h"
#include "dot.h"

int main( int argc, char *argv[] )
{
    QApplication app( argc, argv );
    QGraphicsView view;

    QGraphicsScene *scene = new QGraphicsScene( 0, 0, 300, 300, &view );
    view.setScene( scene );
    scene->setBackgroundBrush( Qt::black );

    SuperItem *super = new SuperItem;
    scene->addItem( super );
    super->setFocus();

    Dot *dot;
    const int step = 30;
    for ( int y = 0; y < 300; y += step )
        for ( int x = 0; x < 300; x += step ) {
            dot = new Dot;
            dot->setPos( x, y );
            scene->addItem( dot );
        }

    view.show();

    return app.exec();
}
