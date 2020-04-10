#include <QApplication>
#include <QtWidgets>

void remove(QWidget *widget)
{
    if (widget)
        delete widget;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton *button = new QPushButton(QStringLiteral("Close"));
    QObject::connect(button, &QPushButton::clicked, [=](){ button->close(); });
    QObject::connect(button, &QPushButton::clicked, [=](){ remove(button); });
    button->show();

    return app.exec();
}
