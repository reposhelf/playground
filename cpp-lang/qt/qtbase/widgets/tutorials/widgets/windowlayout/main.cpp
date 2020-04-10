#include <QtWidgets>

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QWidget window;
    auto label = new QLabel(QApplication::translate("windowLayout", "Name:"));
    auto lineEdit = new QLineEdit;

    auto layout = new QHBoxLayout;
    layout->addWidget(label);
    layout->addWidget(lineEdit);
    window.setLayout(layout);
    window.setWindowTitle(
                QApplication::translate("windowLayout", "Window layout"));
    window.show();

    return app.exec();
}
