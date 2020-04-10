#include <QTimer>
#include <QFile>
#include <QDataStream>
#include <QDebug>
#include <QSettings>
#include "tipofthedaywidget.h"
#include "tipdelegate.h"
#include "ui_tipofthedaywidget.h"

// constructor()

TipOfTheDayWidget::TipOfTheDayWidget(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::TipOfTheDayWidget),
      m_delegate(new TipDelegate),
      Interval(30000)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose, true);
    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);	
    m_config = new QSettings("D:/GP1settings.ini", QSettings::IniFormat, this);
    //m_config = new QSettings("Silego Technology", "GreenPAK1 Designer v.3.00.15", this);
    setCheckBoxState();

    m_timer = new QTimer();
    m_timer->start(Interval);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(close()));
    connect(ui->checkBox, SIGNAL(toggled(bool)), this, SLOT(writeCheckBoxSettings(bool)));

    displayTip();
}

// ~destructor()

TipOfTheDayWidget::~TipOfTheDayWidget()
{
    delete m_delegate;
    delete m_config;
    delete m_timer;
    delete ui;
}

// enterEvent()

void TipOfTheDayWidget::enterEvent(QEvent *)
{
    m_timer->stop();
}

// leaveEvent()

void TipOfTheDayWidget::leaveEvent(QEvent *)
{
    m_timer->start(Interval);
}

// on_closeButton_clicked()

void TipOfTheDayWidget::on_closeButton_clicked()
{
    this->close();
}

// on_nextTipButton_clicked()

void TipOfTheDayWidget::on_nextTipButton_clicked()
{
    m_delegate->nextTip();
    displayTip();
}

// on_previousTipButton_clicked()

void TipOfTheDayWidget::on_previousTipButton_clicked()
{
    m_delegate->previousTip();
    displayTip();
}

// writeCheckBoxSettings()

void TipOfTheDayWidget::writeCheckBoxSettings(bool flag)
{
    int result;
    flag ? result = TipOfTheDayWidget::Checked : result = TipOfTheDayWidget::UnChecked;
    m_config->setValue("TipOfTheDayWidget/checkBox", result);
}

// displayTip()

void TipOfTheDayWidget::displayTip() const
{
    QString tipText = m_delegate->tipText();
    QString tipImagePath = m_delegate->tipImagePath();
    QString tipImageName = m_delegate->tipImageName();
    QTextDocument *doc = new QTextDocument;
    doc->setHtml(tipText);
    doc->addResource(QTextDocument::ImageResource, QUrl(tipImageName), QPixmap(tipImagePath));
    ui->textBrowser->setDocument(doc);
}

// setCheckBoxState()

void TipOfTheDayWidget::setCheckBoxState() const
{
    int value = m_config->value("TipOfTheDayWidget/checkBox").toInt();
    switch (value) {
    case TipOfTheDayWidget::Checked:
        ui->checkBox->setChecked(true);
        break;
    case TipOfTheDayWidget::UnChecked:
        ui->checkBox->setChecked(false);
        break;
    default:
        return;
    }
}
