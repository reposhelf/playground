#ifndef WIDGET_H
#define WIDGET_H

#include "webcrawlerpool.h"

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
    void on_startButton_clicked();
    void on_stopButton_clicked();
    void on_pauseButton_clicked();
    void on_urlLineEdit_textChanged(const QString &arg1);
    void on_textLineEdit_textChanged(const QString &arg1);
    void on_threadsSpinBox_valueChanged(int arg1);
    void on_linksSpinBox_valueChanged(int arg1);
    void onStatusInformationUpdated(const QString &url, const QString &status);

private:
    Ui::Widget *ui;
    WebCrawlerPool m_webCrawlerPool;
};

#endif // WIDGET_H
