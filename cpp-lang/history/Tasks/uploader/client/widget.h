#ifndef WIDGET_H
#define WIDGET_H

#include "sslconnection.h"

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_browseButton_clicked();
    void on_sendButton_clicked();
    void on_exitButton_clicked();

    void updateSendButtonAvailability();

private:
    Ui::Widget *ui;
    SslConnection mSslConnection;
};

#endif // WIDGET_H
