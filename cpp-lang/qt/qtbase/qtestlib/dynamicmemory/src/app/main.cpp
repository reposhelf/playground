#include "dynamicmemory.h"
#include "dynamicmemorywidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    DynamicMemory dm;
    DynamicMemoryWidget widget(&dm);
    widget.show();

    return app.exec();
}
