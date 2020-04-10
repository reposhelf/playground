#include "counter.h"

#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    Counter a;
    Counter b;

    QObject::connect(&a, &Counter::valueChanged, &b, &Counter::setValue);

    qDebug() << a.value() << b.value(); // 0 0
    a.setValue(33);
    qDebug() << a.value() << b.value(); // 33 33
    b.setValue(14);
    qDebug() << a.value() << b.value(); // 33 14

    return 0;
}
