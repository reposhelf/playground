#ifndef COLOWERDIALOG_H
#define COLOWERDIALOG_H

#include <QDialog>
#include <QPalette>

namespace Ui {
    class ColowerDialog;
}

class ColowerDialog : public QDialog
{
    Q_OBJECT
public:
    ColowerDialog(QWidget *parent = 0);

private slots:
    void colorChanged();

private:
    Ui::ColowerDialog *ui;
    QPalette palette;
};

#endif // COLOWERDIALOG_H
