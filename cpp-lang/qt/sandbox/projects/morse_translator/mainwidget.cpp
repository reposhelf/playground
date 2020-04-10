#include "mainwidget.h"

#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextStream>

#include "morsetranslator.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent),
      m_decodedTextEdit(new QTextEdit),
      m_encodedTextEdit(new QTextEdit),
      m_translator(new MorseTranslator(this))
{
    auto loadDecodedTextButton = new QPushButton("Load");
    auto loadEncodedTextButton = new QPushButton("Load");
    auto saveDecodedTextButton = new QPushButton("Save");
    auto saveEncodedTextButton = new QPushButton("Save");

    auto decodedLayout = new QGridLayout;
    decodedLayout->addWidget(m_decodedTextEdit, 0, 0, 4, 4);
    decodedLayout->addWidget(loadDecodedTextButton, 5, 0, 1, 1);
    decodedLayout->addWidget(saveDecodedTextButton, 5, 1, 1, 1);

    auto encodedLayout = new QGridLayout;
    encodedLayout->addWidget(m_encodedTextEdit, 0, 0, 4, 4);
    encodedLayout->addWidget(loadEncodedTextButton, 5, 0, 1, 1);
    encodedLayout->addWidget(saveEncodedTextButton, 5, 1, 1, 1);

    auto mainLayout = new QHBoxLayout(this);
    mainLayout->addLayout(decodedLayout);
    mainLayout->addLayout(encodedLayout);

    connect(loadDecodedTextButton, SIGNAL(clicked()), this, SLOT(loadDecodedTextFile()));
    connect(loadEncodedTextButton, SIGNAL(clicked()), this, SLOT(loadEncodedTextFile()));
    connect(saveDecodedTextButton, SIGNAL(clicked()), this, SLOT(saveDecodedTextFile()));
    connect(saveEncodedTextButton, SIGNAL(clicked()), this, SLOT(saveEncodedTextFile()));

    connect(m_decodedTextEdit, SIGNAL(textChanged()), this, SLOT(updateEncodedText()));
    connect(m_encodedTextEdit, SIGNAL(textChanged()), this, SLOT(updateDecodedText()));

    resize(1400, 800);
}

MainWidget::~MainWidget()
{

}

void MainWidget::loadDecodedTextFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open file"),
                                                    "/home",
                                                    tr("Plain texts (*.txt)"));
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    m_decodedTextEdit->setText(in.readAll());
}

void MainWidget::loadEncodedTextFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open file"),
                                                    "/home",
                                                    tr("Morse texts (*.mrs)"));
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    m_encodedTextEdit->setText(in.readAll());
}

void MainWidget::saveDecodedTextFile()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save file"),
                                                    "/home",
                                                    tr("Plain texts (*.txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << m_decodedTextEdit->toPlainText();
}

void MainWidget::saveEncodedTextFile()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save file"),
                                                    "/home",
                                                    tr("Morse texts (*.mrs)"));
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << m_encodedTextEdit->toPlainText();
}

void MainWidget::updateEncodedText()
{
    QString decodedText = m_decodedTextEdit->toPlainText();
    QString encodedText = m_translator->encode(decodedText);

    m_encodedTextEdit->blockSignals(true);
    m_encodedTextEdit->setText(encodedText);
    m_encodedTextEdit->blockSignals(false);
}

void MainWidget::updateDecodedText()
{
    QString encodedText = m_encodedTextEdit->toPlainText();
    QString decodedText = m_translator->decode(encodedText);

    m_decodedTextEdit->blockSignals(true);
    m_decodedTextEdit->setText(decodedText);
    m_decodedTextEdit->blockSignals(false);
}
