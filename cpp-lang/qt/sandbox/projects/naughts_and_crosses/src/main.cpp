#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "board.h"
#include "controller.h"
#include "result.h"
#include "square.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Square>();

    Controller controller;
    auto board = controller.board();
    auto result = controller.result();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("board", board);
    engine.rootContext()->setContextProperty("result", result);
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
