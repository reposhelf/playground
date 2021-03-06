#include "mainwindow.h"

#include <QtWidgets>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    QString locale = QLocale::system().name();

    QTranslator translator;
    translator.load(QString("arrowpad_") + locale,
                    QCoreApplication::applicationDirPath() + "/lang/");
    a.installTranslator(&translator);

    MainWindow mainWindow;
    mainWindow.show();
    return a.exec();
}
