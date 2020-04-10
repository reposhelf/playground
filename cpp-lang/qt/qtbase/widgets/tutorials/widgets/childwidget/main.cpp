#include <QtWidgets>

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QWidget window;
    window.resize(320, 240);
    window.show();
    window.setWindowTitle(
                QApplication::translate("childWidget", "Child widget"));

    QPushButton *button = new QPushButton(
                QApplication::translate("childWidget", "Press me"), &window);
    button->move(100, 100);
    button->show();

    return app.exec();
}
