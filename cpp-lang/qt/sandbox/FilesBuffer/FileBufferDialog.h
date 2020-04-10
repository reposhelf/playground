#ifndef FILEBUFFERDIALOG_H
#define FILEBUFFERDIALOG_H

#include <QDialog>
#include "FileListWidget.h"

class QListWidget;
class QListButton;

class FileBufferDialog : public QDialog {
    Q_OBJECT

public:
    FileBufferDialog();

public slots:
    void clearItems();
    void deleteItem();
    void saveItem();

private:
    QString openDir( FileBufferDialog* );

    FileListWidget *m_list;
    QPushButton    *m_deleteButton;
    QPushButton    *m_saveButton;
    QPushButton    *m_clearButton;
};

#endif // FILEBUFFERDIALOG_H
