#include "pathdeform.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    bool smallScreen = qApp->arguments().contains("-small-screen");
    PathDeformWidget deformWidget(0, smallScreen);
    QStyle *arthurStyle = new ArthurStyle;
    deformWidget.setStyle(arthurStyle);
    QList<QWidget *> widgets = deformWidget.findChildren<QWidget *>();
    foreach (QWidget *widget, widgets)
        widget->setStyle(arthurStyle);

    if (smallScreen)
        deformWidget.showFullScreen();
    else
        deformWidget.show();

    return app.exec();
}
