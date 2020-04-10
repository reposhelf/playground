#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QActionGroup;
class QLabel;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

protected:
    void contextMenuEvent(QContextMenuEvent *event);

private slots:
    void newFile();
    void open();
    void save();
    void print();
    void undo();
    void redo();
    void cut();
    void copy();
    void paste();
    void bold();
    void italic();
    void leftAlign();
    void rightAlign();
    void justify();
    void center();
    void setLineSpacing();
    void setParagraphSpacing();
    void about();
    void aboutQt();

private:
    void createActions();
    void createMenus();

    QMenu *m_fileMenu;
    QMenu *m_editMenu;
    QMenu *m_formatMenu;
    QMenu *m_helpMenu;
    QActionGroup *m_alignmentGroup;
    QAction *m_newAct;
    QAction *m_openAct;
    QAction *m_saveAct;
    QAction *m_printAct;
    QAction *m_exitAct;
    QAction *m_undoAct;
    QAction *m_redoAct;
    QAction *m_cutAct;
    QAction *m_copyAct;
    QAction *m_pasteAct;
    QAction *m_boldAct;
    QAction *m_italicAct;
    QAction *m_leftAlignAct;
    QAction *m_rightAlignAct;
    QAction *m_justifyAct;
    QAction *m_centerAct;
    QAction *m_setLineSpacingAct;
    QAction *m_setParagraphSpacingAct;
    QAction *m_aboutAct;
    QAction *m_aboutQtAct;
    QLabel *m_infoLabel;
};

#endif // MAINWINDOW_H
