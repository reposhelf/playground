#include "progressdialog.h"

#include <QFileInfo>

ProgressDialog::ProgressDialog(const QString &filePath, QWidget *parent)
    : QProgressDialog(parent)
{
    setWindowTitle(tr("Upload Progress"));
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    QFileInfo fi(filePath);
    setLabelText(tr("Uploading %1.").arg(fi.fileName()));
    setMinimum(0);
    setValue(0);
    setMinimumDuration(0);
}

void ProgressDialog::onUploadProgress(qint64 bytesSent, qint64 totalBytes)
{
    setMaximum(totalBytes);
    setValue(bytesSent);
}
