#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class TextEdit;
class Assistant;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = Q_NULLPTR);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void about();
    void showDocumentation();
    void open();

private:
    void createActions();
    void createMenus();

    TextEdit *_textViewer;
    Assistant *_assistant;

    QMenu *_fileMenu;
    QMenu *_helpMenu;

    QAction *_assistantAct;
    QAction *_clearAct;
    QAction *_openAct;
    QAction *_exitAct;
    QAction *_aboutAct;
    QAction *_aboutQtAct;
};

#endif // MAINWINDOW_H
