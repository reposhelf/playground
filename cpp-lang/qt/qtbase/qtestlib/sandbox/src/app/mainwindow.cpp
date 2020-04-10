#include "mainwindow.h"
#include "cdate.h"
#include "cstring.h"
#include "clabel.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    CString str;
    CDate date;
    const bool d = date.isValid(QDate(1980, 2, 29));

    if (d) {
        CLabel *label = new CLabel(str.up(QString("hello world!")));
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        setCentralWidget(label);
    }
}

MainWindow::~MainWindow()
{
}
