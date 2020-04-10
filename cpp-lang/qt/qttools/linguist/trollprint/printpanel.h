#ifndef PRINTPANEL_H
#define PRINTPANEL_H

#include <QWidget>

class QGroupBox;
class QRadioButton;

class PrintPanel : public QWidget
{
    Q_OBJECT

public:
    explicit PrintPanel(QWidget *parent = Q_NULLPTR);

private:
    QGroupBox *m_twoSidedGroupBox;
    QGroupBox *m_colorsGroupBox;
    QRadioButton *m_twoSidedEnabledRadio;
    QRadioButton *m_twoSidedDisabledRadio;
    QRadioButton *m_colorsEnabledRadio;
    QRadioButton *m_colorsDisabledRadio;
};

#endif // PRINTPANEL_H
