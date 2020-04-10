#include "widget.h"
#include "ui_widget.h"
#include "progressdialog.h"
#include "connectiondata.h"

#include <QFileDialog>
#include <QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->serverPortLineEdit->setValidator(new QIntValidator(0, 65535, this));

    connect(ui->serverNameLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(updateSendButtonAvailability()));
    connect(ui->serverPortLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(updateSendButtonAvailability()));
    connect(ui->fileLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(updateSendButtonAvailability()));

    updateSendButtonAvailability();

    ConnectionData connectionData;
    ui->serverNameLineEdit->setText(connectionData.host());
    ui->serverPortLineEdit->setText(connectionData.port());
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_browseButton_clicked()
{
    ui->fileLineEdit->setText(
                QFileDialog::getOpenFileName(this, tr("Choose File"), "/home"));
}

void Widget::on_sendButton_clicked()
{
    QString serverName = ui->serverNameLineEdit->text();
    int serverPort = ui->serverPortLineEdit->text().toInt();
    QString filePath = ui->fileLineEdit->text();

    mSslConnection.setServerName(serverName);
    mSslConnection.setServerPort(serverPort);

    ProgressDialog *progressDialog = new ProgressDialog(filePath, this);
    progressDialog->setAttribute(Qt::WA_DeleteOnClose);
    connect(progressDialog, SIGNAL(canceled()), &mSslConnection, SIGNAL(uploadCanceled()));
    connect(&mSslConnection, SIGNAL(uploadFinished()), progressDialog, SLOT(hide()));
    connect(&mSslConnection, SIGNAL(uploadProgress(qint64,qint64)),
            progressDialog, SLOT(onUploadProgress(qint64,qint64)));
    progressDialog->show();

    if (mSslConnection.sendFile(filePath) == SslConnection::Fail)
        QMessageBox::critical(this, tr("Panic"), mSslConnection.errorString());
}

void Widget::on_exitButton_clicked()
{
    close();
}

void Widget::updateSendButtonAvailability()
{
    ui->sendButton->setDisabled(
                ui->serverNameLineEdit->text().isEmpty()
                || ui->serverPortLineEdit->text().isEmpty()
                || ui->fileLineEdit->text().isEmpty());
}
