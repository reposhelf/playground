#include <QtWidgets>

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QWidget window;

    auto queryLabel = new QLabel(
                QApplication::translate("nestedLayouts", "Query:"));
    auto queryEdit = new QLineEdit;
    auto resultView = new QTableView;

    auto queryLayout = new QHBoxLayout;
    queryLayout->addWidget(queryLabel);
    queryLayout->addWidget(queryEdit);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addLayout(queryLayout);
    mainLayout->addWidget(resultView);
    window.setLayout(mainLayout);

    // setting up the model
    QStandardItemModel model;
    model.setHorizontalHeaderLabels(
                QStringList() << QApplication::translate("nestedLayouts", "Name")
                              << QApplication::translate("nestedLayouts", "Office"));

    QList<QStringList> rows = QList<QStringList>()
            << (QStringList() << "Verne Nilsen" << "123")
            << (QStringList() << "Carlos Tang" << "77")
            << (QStringList() << "Bronwyn Hawcroft" << "119")
            << (QStringList() << "Alessandro Hanssen" << "32")
            << (QStringList() << "Andrew John Bakken" << "54")
            << (QStringList() << "Vanessa Weatherley" << "85")
            << (QStringList() << "Rebecca Dickens" << "17")
            << (QStringList() << "David Bradley" << "42")
            << (QStringList() << "Knut Walters" << "25")
            << (QStringList() << "Andrea Jones" << "34");

    foreach (QStringList row, rows) {
        QList<QStandardItem *> items;
        foreach (QString text, row) {
            items.append(new QStandardItem(text));
        }
        model.appendRow(items);
    }

    resultView->setModel(&model);
    resultView->verticalHeader()->hide();
    resultView->horizontalHeader()->setStretchLastSection(true);

    window.setWindowTitle(
                QApplication::translate("nestedLayouts", "Nested layout"));
    window.show();

    return app.exec();
}
