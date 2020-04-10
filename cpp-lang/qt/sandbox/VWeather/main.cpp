#include <QApplication>
#include "weatherwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    WeatherWidget weatherWidget;
    weatherWidget.show();
    return app.exec();
}
