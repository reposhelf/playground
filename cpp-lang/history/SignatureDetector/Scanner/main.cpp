#include "scanner.h"

#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Scanner scanner(":/signatures.txt");
    bool infected = false;
    QString result = scanner.scanFile(":/signatures.txt", &infected);
    if (infected)
        qDebug() << result;

    return a.exec();
}
