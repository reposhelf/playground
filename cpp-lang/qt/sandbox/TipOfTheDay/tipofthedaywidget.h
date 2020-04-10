#ifndef TIPOFTHEDAYWIDGET_H
#define TIPOFTHEDAYWIDGET_H

#include <QDialog>

namespace Ui {
    class TipOfTheDayWidget;
}

class TipDelegate;
class QSettings;
class QTimer;

class TipOfTheDayWidget : public QDialog
{
    Q_OBJECT

public:
    enum {
        Checked   =  1,
        UnChecked = -1
    };

    TipOfTheDayWidget  (QWidget *parent = 0);
    ~TipOfTheDayWidget ();

protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

private slots:
    void on_closeButton_clicked       ();
    void on_nextTipButton_clicked     ();
    void on_previousTipButton_clicked ();
    void writeCheckBoxSettings        (bool flag);

private:
    void displayTip        () const;
    void setCheckBoxState  () const;

    Ui::TipOfTheDayWidget *ui;
    TipDelegate           *m_delegate;
    QSettings             *m_config;
    QTimer                *m_timer;

    const int Interval;
};

#endif // TIPOFTHEDAYWIDGET_H
