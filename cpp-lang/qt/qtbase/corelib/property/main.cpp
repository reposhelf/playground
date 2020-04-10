#include "myclass.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv);

    MyClass myClass;
    myClass.setProperty("priority", "VeryHigh");
    myClass.setName("MyClass");

    return 0;
}
