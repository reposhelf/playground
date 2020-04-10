#include "xform.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    XFormWidget widget(0);
    QStyle *arthurStyle = new ArthurStyle;
    widget.setStyle(arthurStyle);

    QList<QWidget *> widgets = widget.findChildren<QWidget *>();
    foreach (QWidget *w, widgets) {
        w->setStyle(arthurStyle);
        w->setAttribute(Qt::WA_AcceptTouchEvents);
    }
    widget.show();

    return app.exec();
}
