#include <QApplication>
#include "FileBufferDialog.h"

int main( int argc, char *argv[] )
{
    QApplication app( argc, argv );

    FileBufferDialog dlg;
    dlg.resize( 400, 200 );
    dlg.show();

    return app.exec();
}
