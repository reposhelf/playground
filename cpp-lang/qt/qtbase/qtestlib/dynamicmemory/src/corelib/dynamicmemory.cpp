#include "dynamicmemory.h"
#include "dynamicmemorypreset.h"

#include <QStandardItemModel>

DynamicMemory::DynamicMemory(const QString &name, QObject *parent)
    : QObject(parent),
      _name(name),
      _model(new QStandardItemModel(this))
{
    reset();
}

DynamicMemory::~DynamicMemory()
{
    for (int i = 0; i < _model->rowCount(); ++i)
        destroyPreset(i);
}

QAbstractItemModel *DynamicMemory::model() const
{
    return _model;
}

QStringList DynamicMemory::presetNames() const
{
    QStringList names;
    for (int i = 0; i < _model->rowCount(); ++i)
    {
        DynamicMemoryPreset *dmp = preset(i);
        names.append(dmp->name());
    }
    return names;
}

void DynamicMemory::setName(const QString &n)
{
    if (name() == n)
        return;
    _name = n;
}

void DynamicMemory::setStatusFlags(DynamicMemory::StatusFlags flags)
{
    if (_statusFlags == flags)
        return;

    _statusFlags = flags;
    emit statusFlagsChanged(_statusFlags);
}

DynamicMemory::AddStatus DynamicMemory::newPreset(const QString &n)
{
    if (_model->rowCount() == MaxPresetCount)
        return AS_OwerflowAdd;

    // remove single Preset if it's null:
    if (_model->rowCount() == 1)
    {
        DynamicMemoryPreset *dmp = preset(_model->rowCount() - 1);
        if (dmp->isNull())
            _model->clear();
    }
    makePreset(false, n);

    return AS_NormalAdd;
}

DynamicMemory::DeleteStatus DynamicMemory::deletePreset(int index)
{
    if (index < 0 || index >= _model->rowCount())
        return DS_OutOfRangeDelete;

    if (_model->rowCount() == 1)
    {
        DynamicMemoryPreset *dmp = preset(_model->rowCount() - 1);
        if (dmp->isNull())
            return DS_NullPresetDelete;
    }
    destroyPreset(index);

    if (_model->rowCount() == 0)
        reset();

    return DS_NormalDelete;
}

void DynamicMemory::reset()
{
    /*
     * Sets single preset into the model. This means that
     * the preset has name 'None' and it's null.
     * Use in case the model has no presets added by user.
     */

    makePreset(true);
}

void DynamicMemory::makePreset(bool shouldBeNull, const QString &n)
{
    DynamicMemoryPreset *dmp = new DynamicMemoryPreset;
    if (!shouldBeNull)
    {
        dmp->setOwner(this);
        dmp->setName(n);
    }
    QStandardItem *item = new QStandardItem;
    item->setData(QVariant::fromValue(dmp));
    item->setText(dmp->name());
    _model->appendRow(item);

    updatedStatusFlags();
}

void DynamicMemory::destroyPreset(int index)
{
    delete preset(index);
    _model->removeRow(index);

    updatedStatusFlags();
}

DynamicMemoryPreset *DynamicMemory::preset(int index) const
{
    if ((index < 0) || (index >= _model->rowCount()))
        return 0;
    QModelIndex i = _model->index(index, 0);
    QVariant data = i.data(Qt::UserRole + 1);
    return data.value<DynamicMemoryPreset *>();
}

void DynamicMemory::updatedStatusFlags()
{
    if ((_model->rowCount() == 1) && (preset(_model->rowCount() - 1)->isNull()))
                setStatusFlags(SF_Empty);

    else if ((_model->rowCount() > 0) && (_model->rowCount() < MaxPresetCount))
        setStatusFlags(SF_Editable);

    else if (_model->rowCount() == MaxPresetCount)
        setStatusFlags(SF_Full);
}
