#include "mdichild.h"

#include <QtWidgets>

MdiChild::MdiChild(QWidget *parent)
    : QTextEdit(parent),
      m_currentFile(),
      m_isUntitled(true)
{
    setAttribute(Qt::WA_DeleteOnClose);
}

void MdiChild::newFile()
{
    static int sequenceNumber = 1;
    m_isUntitled = true;
    m_currentFile = tr("document%1.txt").arg(sequenceNumber++);
    setWindowTitle(m_currentFile + "[*]");

    connect(document(), &QTextDocument::contentsChanged, this, &MdiChild::documentWasModified);
}

bool MdiChild::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this,
                             tr("MDI"),
                             tr("Cannot open file %0:\n%1")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }
    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);

    connect(document(), &QTextDocument::contentsChanged, this, &MdiChild::documentWasModified);

    return true;
}

bool MdiChild::save()
{
    if (m_isUntitled)
        return saveAs();
    else
        return saveFile(m_currentFile);
}

bool MdiChild::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), m_currentFile);
    if (fileName.isEmpty())
        return false;

    return saveFile(fileName);
}

bool MdiChild::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this,
                             tr("MDI"),
                             tr("Cannot write file %0:\n%1")
                             .arg(QDir::toNativeSeparators(fileName))
                             .arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << toPlainText();
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);
    return true;
}

QString MdiChild::userFriendlyCurrentFile()
{
    return strippedName(m_currentFile);
}

void MdiChild::closeEvent(QCloseEvent *event)
{
    if (maybeSave())
        event->accept();
    else
        event->ignore();
}

void MdiChild::documentWasModified()
{
    setWindowModified(document()->isModified());
}

bool MdiChild::maybeSave()
{
    if (!document()->isModified())
        return true;
    const QMessageBox::StandardButton ret
            = QMessageBox::warning(this,
                                   tr("MDI"),
                                   tr("%0 has been modified.\n"
                                      "Do you want to save your chanes?")
                                   .arg(userFriendlyCurrentFile()),
                                   QMessageBox::Save
                                   | QMessageBox::Discard
                                   | QMessageBox::Cancel);
    switch (ret) {
    case QMessageBox::Save:
        return save();
    case QMessageBox::Cancel:
        return false;
    default:
        break;
    }
    return true;
}

void MdiChild::setCurrentFile(const QString &fileName)
{
    m_currentFile = QFileInfo(fileName).canonicalFilePath();
    m_isUntitled = false;
    document()->setModified(false);
    setWindowModified(false);
    setWindowTitle(userFriendlyCurrentFile() + "[*]");
}

QString MdiChild::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}
