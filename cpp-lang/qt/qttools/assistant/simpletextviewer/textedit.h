#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QTextEdit>
#include <QUrl>

class TextEdit : public QTextEdit
{
    Q_OBJECT

public:
    explicit TextEdit(QWidget *parent = Q_NULLPTR);
    void setContents(const QString &fileName);

private:
    QVariant loadResource(int type, const QUrl &name);
    QUrl _srcUrl;
};

#endif // TEXTEDIT_H
