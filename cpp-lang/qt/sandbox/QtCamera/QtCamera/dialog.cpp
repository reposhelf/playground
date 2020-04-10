#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    videoCapture.open(0);
    if (videoCapture.isOpened() == false) {
        ui->lblDisplay->setText("error: camera not accessed succesfully");
        return;
    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGUI()));
    timer->start(20);

    ui->btnPhoto->setIcon(QIcon(":/images/btn_ph_icon.png"));
    ui->btnVideo->setIcon(QIcon(":/images/btn_v_icon.png"));
    ui->btnExit->setIcon(QIcon(":/images/btn_exit.png"));
    setWindowIcon(QIcon(":/images/win_icon.png"));

    setFixedSize(760, 520);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::updateGUI()
{
    videoCapture.read(matOriginal);

    if (matOriginal.empty() == true) return;

    cv::cvtColor(matOriginal, matOriginal, CV_BGR2RGB);
    QImage imgOriginal((uchar*)matOriginal.data, matOriginal.cols,
                        matOriginal.rows, matOriginal.step,
                        QImage::Format_RGB888);
    ui->lblDisplay->setPixmap(QPixmap::fromImage(imgOriginal));

    // write video to file
    if (writer.isOpened()) {
        cv::cvtColor(matOriginal, matOriginal, CV_RGB2BGR);
        writer << matOriginal;
    }
}

void Dialog::on_btnExit_clicked()
{
    QCoreApplication::quit();
}

void Dialog::on_btnPhoto_clicked()
{
    std::string fileName = "../output/Photos/qtc_" + currentDateTime() + ".jpg";
    cv::cvtColor(matOriginal, matOriginal, CV_BGR2RGB);
    cv::imwrite(fileName, matOriginal);
}

void Dialog::on_btnVideo_clicked()
{
    QMovie *movie = new QMovie(":/images/video_shoot.gif");
    ui->lblGif->setMovie(movie);
    if (writer.isOpened()) {
        writer.~VideoWriter();
        ui->btnVideo->setIcon(QIcon(":/images/btn_v_icon.png"));
    } else {
        std::string fileName = "../output/Videos/qtc_" + currentDateTime() + ".avi";
        int fps = 30;
        int width = videoCapture.get(CV_CAP_PROP_FRAME_WIDTH);
        int height = videoCapture.get(CV_CAP_PROP_FRAME_HEIGHT);
        writer.open(fileName, CV_FOURCC('X', 'V', 'I', 'D'), fps, cvSize(width, height), 1);
        movie->start();
        ui->btnVideo->setIcon(QIcon(":/images/btn_vstop_icon.png"));
    }
}

const std::string Dialog::currentDateTime()
{
    time_t now = time(0);
    struct tm tstruct;
    char buff[80];
    tstruct = *localtime(&now);
    strftime(buff, sizeof(buff), "%Y-%m-%d-%H-%M-%S", &tstruct);
    return buff;
}

