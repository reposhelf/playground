#include "window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName(QStringLiteral("Rio Engineiro"));
    QCoreApplication::setOrganizationDomain(QStringLiteral("rioengineiro.org"));
    QCoreApplication::setApplicationName(QStringLiteral("SettingsPlay"));

    QApplication app(argc, argv);

    Window w;
    w.show();

    return app.exec();
}
