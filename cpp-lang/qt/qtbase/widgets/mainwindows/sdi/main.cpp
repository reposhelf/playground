#include "mainwindow.h"

#include <QApplication>
#include <QCommandLineParser>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QCoreApplication::setApplicationName("SDI Example");
    QCoreApplication::setOrganizationName("QtProject");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::applicationName());
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("file", "The file(s) to open.");
    parser.process(app);

    MainWindow *window = Q_NULLPTR;
    foreach (const QString &file, parser.positionalArguments()) {
        MainWindow *newWindow = new MainWindow(file);
        newWindow->tile(window);
        newWindow->show();
        window = newWindow;
    }
    if (!window)
        window = new MainWindow;
    window->show();

    return app.exec();
}
