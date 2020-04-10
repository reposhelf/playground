#include <QApplication>

#include "arthurstyle.h"
#include "compositionwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ArthurStyle *style = new ArthurStyle;
    CompositionWidget w;
    w.setStyle(style);
    QList<QWidget *> widgets = w.findChildren<QWidget *>();
    for (auto widget : widgets)
        widget->setStyle(style);
    w.show();
    return app.exec();
}
