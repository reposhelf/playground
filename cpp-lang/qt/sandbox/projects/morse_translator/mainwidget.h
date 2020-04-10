#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QTextEdit>
#include <QWidget>

#include "abstracttranslator.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

private slots:
    void loadDecodedTextFile();
    void loadEncodedTextFile();
    void saveDecodedTextFile();
    void saveEncodedTextFile();
    void updateEncodedText();
    void updateDecodedText();

private:
    QTextEdit *m_decodedTextEdit;
    QTextEdit *m_encodedTextEdit;
    AbstractTranslator *m_translator;
};

#endif // MAINWIDGET_H
