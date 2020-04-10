#ifndef WIDGET_H
#define WIDGET_H

#include "scalculator.h"

#include <QWidget>

namespace Ui {
class Widget;
}

class QSignalMapper;
class Widget : public QWidget
{
    Q_OBJECT

    enum EditState { ES_Append, ES_Replace };

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void onDigitButtonClicked(const QString &text);
    void onOperatorButtonClicked(const QString &text);
    void onTextChanged(const QString &text);
    void onClearButtonClicked();

private:
    Ui::Widget *ui;
    QSignalMapper *m_digitSignalMapper;
    QSignalMapper *m_operatorSignalMapper;
    EditState m_editState = ES_Replace;
    SCalculator m_calculator;
};

#endif // WIDGET_H
