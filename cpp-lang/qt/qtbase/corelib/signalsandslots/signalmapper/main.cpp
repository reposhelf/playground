#include "buttonwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ButtonWidget widget;
    widget.show();

    return app.exec();
}
