#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "superitem.h"

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

    view.show();
    return app.exec();
}
