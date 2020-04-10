#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include <QMovie>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <time.h>
#include <stdio.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;

    cv::VideoCapture videoCapture;
    cv::VideoWriter writer;
    cv::Mat matOriginal;
    QImage imgOriginal;
    QTimer *timer;

private slots:
    void on_btnExit_clicked();
    void on_btnPhoto_clicked();
    void on_btnVideo_clicked();

    void updateGUI();
    //for adding to files names
    const std::string currentDateTime();
};

#endif // DIALOG_H
