#include "dynamicmemorywidget.h"
#include "ui_dynamicmemorywidget.h"
#include "presetnamedialog.h"

DynamicMemoryWidget::DynamicMemoryWidget(DynamicMemory *dm, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DynamicMemoryWidget),
    _dm(dm)
{
    ui->setupUi(this);

    ui->presetNameComboBox->setModel(_dm->model());

    connect(ui->addNameButton, &QToolButton::clicked,
            this, &DynamicMemoryWidget::onAddButtonClicked);
    connect(ui->removeNameButton, &QToolButton::clicked,
            this, &DynamicMemoryWidget::onRemoveButtonClicked);
    connect(_dm, &DynamicMemory::statusFlagsChanged,
            this, &DynamicMemoryWidget::onDynamicMemoryStatusChanged);

    generateOption0(ui->optionComboBox_0);
    generateOption1(ui->optionComboBox_1);
    updateControls();
}

DynamicMemoryWidget::~DynamicMemoryWidget()
{
    delete ui;
}

void DynamicMemoryWidget::onAddButtonClicked()
{
    PresetNameDialog dialog(_dm->presetNames(), qApp->activeWindow());
    if (dialog.exec())
    {
        _dm->newPreset(dialog.presetName());
        ui->presetNameComboBox->setCurrentText(dialog.presetName());
//        if (isCurrentPresetNull())
//            ui->presetNameComboBox->clear();

//        Preset preset(dialog.presetName());
//        preset.setSliceIndex(_dm->takeFreeSliceIndex());
//        preset.setSlice(_dm->freeSlice(preset.sliceIndex()));
//        QVariant data;
//        data.setValue(preset);

//        ui->presetNameComboBox->addItem(preset.name(), data);
//        ui->presetNameComboBox->setCurrentText(preset.name());

        updateControls();
    }
}

void DynamicMemoryWidget::onRemoveButtonClicked()
{
    _dm->deletePreset(ui->presetNameComboBox->currentIndex());
//    if (isCurrentPresetNull())
//        return;

//    QVariant data = ui->presetNameComboBox->currentData();
//    Preset preset = data.value<Preset>();
//    preset.resetSlice();
//    _dm->addFreeSliceIndex(preset.sliceIndex());

//    ui->presetNameComboBox->removeItem(ui->presetNameComboBox->currentIndex());
//    if (ui->presetNameComboBox->count() == 0)
//        _dm->reset();

    updateControls();
}

void DynamicMemoryWidget::onDynamicMemoryStatusChanged(DynamicMemory::StatusFlags flags)
{
    if (flags & DynamicMemory::SF_Empty)
    {
        generateOption0(ui->optionComboBox_0);
        generateOption1(ui->optionComboBox_1);
    }
}

void DynamicMemoryWidget::updateControls() const
{
    ui->presetNameComboBox->setEnabled(_dm->statusFlags() & DynamicMemory::SF_Full);
    ui->optionComboBox_0->setEnabled(_dm->statusFlags() & DynamicMemory::SF_Full);
    ui->optionComboBox_1->setEnabled(_dm->statusFlags() & DynamicMemory::SF_Full);

    ui->addNameButton->setEnabled(_dm->statusFlags() & DynamicMemory::SF_Empty);
    ui->removeNameButton->setEnabled(_dm->statusFlags() & DynamicMemory::SF_Full);

//    generateOption0(ui->optionComboBox_0);
//    generateOption1(ui->optionComboBox_1);
}

void DynamicMemoryWidget::generateOption0(QComboBox *combo) const
{
    combo->clear();

    if (_dm->statusFlags() == DynamicMemory::SF_Empty)
    {
        combo->addItem(QString("None"));
        return;
    }

    combo->addItem(QString("Value 1"));
    combo->addItem(QString("Value 2"));
    combo->addItem(QString("Value 3"));
    combo->addItem(QString("Value 4"));
}

void DynamicMemoryWidget::generateOption1(QComboBox *combo) const
{
    combo->clear();

    if (_dm->statusFlags() == DynamicMemory::SF_Empty)
    {
        combo->addItem(QString("None"));
        return;
    }

    combo->addItem(QString("Disable"));
    combo->addItem(QString("Enable"));
}

//bool DynamicMemoryWidget::isCurrentPresetNull() const
//{
//    if (ui->presetNameComboBox->count() != 1)
//        return false;

//    QVariant data = ui->presetNameComboBox->currentData();
//    Preset preset = data.value<Preset>();

//    return preset.isNull();
//}
