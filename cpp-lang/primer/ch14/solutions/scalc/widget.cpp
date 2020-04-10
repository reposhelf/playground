#include "widget.h"
#include "ui_widget.h"

#include <QtWidgets>

#include <QDebug>

static const QString START_VALUE_STR = "0";

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_digitSignalMapper(new QSignalMapper(this)),
    m_operatorSignalMapper(new QSignalMapper(this))
{
    ui->setupUi(this);

    connect(ui->button_0, SIGNAL(clicked()), m_digitSignalMapper, SLOT(map()));
    connect(ui->button_1, SIGNAL(clicked()), m_digitSignalMapper, SLOT(map()));
    connect(ui->button_2, SIGNAL(clicked()), m_digitSignalMapper, SLOT(map()));
    connect(ui->button_3, SIGNAL(clicked()), m_digitSignalMapper, SLOT(map()));
    connect(ui->button_4, SIGNAL(clicked()), m_digitSignalMapper, SLOT(map()));
    connect(ui->button_5, SIGNAL(clicked()), m_digitSignalMapper, SLOT(map()));
    connect(ui->button_6, SIGNAL(clicked()), m_digitSignalMapper, SLOT(map()));
    connect(ui->button_7, SIGNAL(clicked()), m_digitSignalMapper, SLOT(map()));
    connect(ui->button_8, SIGNAL(clicked()), m_digitSignalMapper, SLOT(map()));
    connect(ui->button_9, SIGNAL(clicked()), m_digitSignalMapper, SLOT(map()));

    m_digitSignalMapper->setMapping(ui->button_0, ui->button_0->text());
    m_digitSignalMapper->setMapping(ui->button_1, ui->button_1->text());
    m_digitSignalMapper->setMapping(ui->button_2, ui->button_2->text());
    m_digitSignalMapper->setMapping(ui->button_3, ui->button_3->text());
    m_digitSignalMapper->setMapping(ui->button_4, ui->button_4->text());
    m_digitSignalMapper->setMapping(ui->button_5, ui->button_5->text());
    m_digitSignalMapper->setMapping(ui->button_6, ui->button_6->text());
    m_digitSignalMapper->setMapping(ui->button_7, ui->button_7->text());
    m_digitSignalMapper->setMapping(ui->button_8, ui->button_8->text());
    m_digitSignalMapper->setMapping(ui->button_9, ui->button_9->text());

    connect(m_digitSignalMapper, SIGNAL(mapped(QString)),
            this, SLOT(onDigitButtonClicked(QString)));

    connect(ui->addButton, SIGNAL(clicked()), m_operatorSignalMapper, SLOT(map()));
    connect(ui->subButton, SIGNAL(clicked()), m_operatorSignalMapper, SLOT(map()));
    connect(ui->mulButton, SIGNAL(clicked()), m_operatorSignalMapper, SLOT(map()));
    connect(ui->divButton, SIGNAL(clicked()), m_operatorSignalMapper, SLOT(map()));
    connect(ui->modButton, SIGNAL(clicked()), m_operatorSignalMapper, SLOT(map()));
    connect(ui->resButton, SIGNAL(clicked()), m_operatorSignalMapper, SLOT(map()));

    m_operatorSignalMapper->setMapping(ui->addButton, ui->addButton->text());
    m_operatorSignalMapper->setMapping(ui->subButton, ui->subButton->text());
    m_operatorSignalMapper->setMapping(ui->mulButton, ui->mulButton->text());
    m_operatorSignalMapper->setMapping(ui->divButton, ui->divButton->text());
    m_operatorSignalMapper->setMapping(ui->modButton, ui->modButton->text());
    m_operatorSignalMapper->setMapping(ui->resButton, ui->resButton->text());

    connect(m_operatorSignalMapper, SIGNAL(mapped(QString)), this,
            SLOT(onOperatorButtonClicked(QString)));

    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(onClearButtonClicked()));

    onClearButtonClicked();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onDigitButtonClicked(const QString &text)
{
    if (m_editState == ES_Replace || ui->lineEdit->text() == START_VALUE_STR) {
        ui->lineEdit->clear();
        ui->lineEdit->setText(text);
        m_editState = ES_Append;
    } else {  // m_editState == ES_Append
        ui->lineEdit->insert(text);
    }
}

void Widget::onOperatorButtonClicked(const QString &text)
{
    m_editState = ES_Replace;

    m_calculator.updateOperator(text.toStdString());
    ui->lineEdit->blockSignals(true);
    ui->lineEdit->setText(QString::fromStdString(m_calculator.result()));
    ui->lineEdit->blockSignals(false);
}

void Widget::onTextChanged(const QString &text)
{
    m_calculator.updateValue(text.toStdString());
}

void Widget::onClearButtonClicked()
{
    m_calculator.clear();

    ui->lineEdit->setText("0");
}
