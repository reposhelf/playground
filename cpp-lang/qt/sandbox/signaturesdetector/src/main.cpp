#include "signaturesdetector.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SignaturesDetector widget;
    widget.show();

    return app.exec();
}
