#include <QApplication>
#include "tipofthedaywidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TipOfTheDayWidget tipOfTheDay;
    tipOfTheDay.show();
    return app.exec();
}
