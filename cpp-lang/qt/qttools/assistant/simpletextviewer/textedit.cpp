#include "textedit.h"

#include <QFile>
#include <QFileInfo>

TextEdit::TextEdit(QWidget *parent)
    : QTextEdit(parent),
      _srcUrl()
{
    setReadOnly(true);
}

void TextEdit::setContents(const QString &fileName)
{
    QFileInfo fi(fileName);
    _srcUrl = QUrl::fromLocalFile(fi.absoluteFilePath());
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly)) {
        QString data(file.readAll());
        if (fileName.endsWith(".html")) {
            setHtml(data);
        } else {
            setPlainText(data);
        }
    }
}

QVariant TextEdit::loadResource(int type, const QUrl &name)
{
    if (type == QTextDocument::ImageResource) {
        QFile file(_srcUrl.resolved(name).toLocalFile());
        if (file.open(QIODevice::ReadOnly))
            return file.readAll();
    }
    return QTextEdit::loadResource(type, name);
}
