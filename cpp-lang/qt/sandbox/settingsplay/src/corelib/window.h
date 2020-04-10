#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QLineEdit;
class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = Q_NULLPTR);
    ~Window();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void onButtonClicked();

private:
    QLineEdit *m_lineEdit;

    void readSettings();
};

#endif // WINDOW_H
