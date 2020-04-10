#include "colowerdialog.h"
#include "ui_colowerdialog.h"


ColowerDialog::ColowerDialog(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::ColowerDialog)
{
    ui->setupUi(this);

    ui->labelRDecVal->setText("0");
    ui->labelGDecVal->setText("0");
    ui->labelBDecVal->setText("0");

    palette.setColor(QPalette::Window, QColor(ui->sliderR->value(),
                                              ui->sliderG->value(),
                                              ui->sliderB->value()));
    ui->labelColor->setAutoFillBackground(true);
    ui->labelColor->setPalette(palette);

    connect(ui->sliderR, SIGNAL(valueChanged(int)), this, SLOT(colorChanged()));
    connect(ui->sliderG, SIGNAL(valueChanged(int)), this, SLOT(colorChanged()));
    connect(ui->sliderB, SIGNAL(valueChanged(int)), this, SLOT(colorChanged()));
}

void ColowerDialog::colorChanged()
{
    palette.setColor(QPalette::Window, QColor(ui->sliderR->value(),
                                              ui->sliderG->value(),
                                              ui->sliderB->value()));
    ui->labelColor->setPalette(palette);
}

