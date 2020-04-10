#include "gradientwidget.h"
#include "arthurstyle.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    GradientWidget widget;

    ArthurStyle *style = new ArthurStyle();
    widget.setStyle(style);
    QList<QWidget *> widgets = widget.findChildren<QWidget *>();
    for (auto w : widgets) {
        w->setStyle(style);
        w->setAttribute(Qt::WA_AcceptTouchEvents);
    }

    widget.show();

    return app.exec();
}
