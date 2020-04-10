#ifndef DRAWDIALOG_H
#define DRAWDIALOG_H

#include <QDialog>
#include "ui_drawdialog.h"

class DrawDialog : public QDialog, public Ui::DrawDialog
{
    Q_OBJECT
public:
    DrawDialog(QWidget *parent = 0);
private slots:
    void generate();
private:
    void qualificationInit();
    void qualificationGenerate();
    void display(QStringList &teams);
    void displayMyTeam();
    QMap<QString, quint8> m_teams;
};

#endif // DRAWDIALOG_H
