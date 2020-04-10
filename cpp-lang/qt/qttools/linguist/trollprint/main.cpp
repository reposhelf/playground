#include "mainwindow.h"

#include <QtWidgets>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

//    QString locale = QLocale::system().name();

    QTranslator translator;
    translator.load("trollprint_pt"/* + locale*/);
    a.installTranslator(&translator);

    MainWindow mainWindow;
    mainWindow.show();
    return a.exec();
}
