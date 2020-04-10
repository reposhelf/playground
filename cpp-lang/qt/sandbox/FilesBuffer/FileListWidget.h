#ifndef FILELISTWIDGET_H
#define FILELISTWIDGET_H

#include <QtGui>
#include <QListWidget>

class FileListWidget : public QListWidget {
    Q_OBJECT

public:
    FileListWidget (QWidget *parent = 0 );

    void setNewCurrentItem();

protected:
    void dragEnterEvent ( QDragEnterEvent* );
    void dropEvent      ( QDropEvent* );
    void mousePressEvent( QMouseEvent* );
    void mouseMoveEvent ( QMouseEvent* );
    void dragMoveEvent  ( QDragMoveEvent* );

private:
    void startDrag();

    QListWidgetItem *m_newCurrentItem;
    QPoint           m_startPos;
};

#endif // FILELISTWIDGET_H
