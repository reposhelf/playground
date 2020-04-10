#include "widget.h"
#include "ui_widget.h"
#include "inputdata.h"

#include <QMessageBox>

#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(&m_webCrawlerPool, SIGNAL(statusInformationUpdated(QString,QString)),
            this, SLOT(onStatusInformationUpdated(QString,QString)), Qt::QueuedConnection);
    connect(&m_webCrawlerPool, SIGNAL(progressChanged(int)), ui->progressBar, SLOT(setValue(int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startButton_clicked()
{
    if (!InputData::instance()->isValid()) {
        QMessageBox::critical(this, "Text Finder", InputData::instance()->errorString());
        return;
    }

    ui->tableWidget->setRowCount(0);
    ui->progressBar->reset();

    m_webCrawlerPool.setSize(InputData::instance()->maxThreads());
    m_webCrawlerPool.setMaxLinksAmount(InputData::instance()->maxLinks());
    m_webCrawlerPool.setStartUrl(InputData::instance()->startUrl());
    m_webCrawlerPool.setTextForSearch(InputData::instance()->textForSearch());
    m_webCrawlerPool.start();
}

void Widget::on_stopButton_clicked()
{
    // TODO
}

void Widget::on_pauseButton_clicked()
{
    // TODO
}

void Widget::on_urlLineEdit_textChanged(const QString &arg1)
{
    InputData::instance()->setStartUrl(arg1);
}

void Widget::on_textLineEdit_textChanged(const QString &arg1)
{
    InputData::instance()->setTextForSearch(arg1);
}

void Widget::on_threadsSpinBox_valueChanged(int arg1)
{
    InputData::instance()->setMaxThreads(arg1);
}

void Widget::on_linksSpinBox_valueChanged(int arg1)
{
    InputData::instance()->setMaxLinks(arg1);
}

void Widget::onStatusInformationUpdated(const QString &url, const QString &status)
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    int row = ui->tableWidget->rowCount() - 1;
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(url));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(status));
}
