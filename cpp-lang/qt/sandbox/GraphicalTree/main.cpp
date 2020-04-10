#include <QApplication>
#include <QMainWindow>

#include "visualtreewidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow mainWindow;
    VisualTreeWidget *widget = new VisualTreeWidget;

    mainWindow.setCentralWidget(widget);

    mainWindow.show();
    return app.exec();
}
