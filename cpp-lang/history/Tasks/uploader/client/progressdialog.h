#ifndef PROGRESSDIALOG_H
#define PROGRESSDIALOG_H

#include <QProgressDialog>

class ProgressDialog : public QProgressDialog
{
    Q_OBJECT
public:
    ProgressDialog(const QString &filePath, QWidget *parent = Q_NULLPTR);

public slots:
    void onUploadProgress(qint64 bytesSent, qint64 totalBytes);
};

#endif // PROGRESSDIALOG_H
