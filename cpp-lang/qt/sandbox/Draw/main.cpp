#include <QApplication>
#include "drawdialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    DrawDialog dlg;
    dlg.show();
    return app.exec();
}
