#include <QApplication>
#include <QPushButton>
#include <QTranslator>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QTranslator translator;
    translator.load("hellotr_la", QCoreApplication::applicationDirPath() + "/lang/");
    app.installTranslator(&translator);

    QPushButton button(QPushButton::tr("Hello world!"));
    button.resize(100, 30);

    button.show();
    return app.exec();
}
