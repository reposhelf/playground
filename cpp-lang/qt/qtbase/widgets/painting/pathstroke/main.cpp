#include <QApplication>

#include "pathstrokewidget.h"
#include "arthurstyle.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    PathStrokeWidget pathStrokeWidget(false);

    ArthurStyle *style = new ArthurStyle;
    pathStrokeWidget.setStyle(style);

    QList<QWidget *> widgets = pathStrokeWidget.findChildren<QWidget *>();
    for (QWidget *w : widgets)
        w->setStyle(style);

    pathStrokeWidget.show();

    return app.exec();
}
