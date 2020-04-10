#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class ArrowPad;
class QMenu;
class QAction;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private:
    ArrowPad *m_arrowPad;
    QMenu *m_fileMenu;
    QAction *m_exitAct;
};

#endif // MAINWINDOW_H
