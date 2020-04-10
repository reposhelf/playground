#include <QApplication>
#include "colowerdialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ColowerDialog colowerDialog;
    colowerDialog.show();
    return app.exec();
}
