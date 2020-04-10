#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QMenu;

class PrintPanel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = Q_NULLPTR);

private slots:
    void about();

private:
    void createActions();
    void createMenus();

    PrintPanel *m_printPanel;
    QMenu *m_fileMenu;
    QMenu *m_helpMenu;
    QAction *m_exitAct;
    QAction *m_aboutAct;
    QAction *m_aboutQtAct;
};

#endif // MAINWINDOW_H
