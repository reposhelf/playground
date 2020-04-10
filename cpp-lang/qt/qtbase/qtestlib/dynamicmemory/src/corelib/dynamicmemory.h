#ifndef DYNAMICMEMORY_H
#define DYNAMICMEMORY_H

#include "corelib_global.h"

#include <QObject>
#include <QString>
#include <QVector>

class QAbstractItemModel;
class QStandardItemModel;
class DynamicMemoryPreset;
class CORELIBSHARED_EXPORT DynamicMemory : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)

public:
    enum AddStatus
    {
        AS_NormalAdd,
        AS_OwerflowAdd
    };
    Q_ENUM(AddStatus)

    enum DeleteStatus
    {
        DS_NormalDelete,
        DS_NullPresetDelete,
        DS_OutOfRangeDelete
    };
    Q_ENUM(DeleteStatus)

    enum StatusFlag
    {
        SF_Empty = 0x1,
        SF_Full = 0x2,
        SF_Editable = SF_Empty | SF_Full
    };
    Q_ENUM(StatusFlag)
    Q_DECLARE_FLAGS(StatusFlags, StatusFlag)

    enum
    {
        MaxPresetCount = 6,
        RegAddressOperatingModeSize = 18
    };

    explicit DynamicMemory(const QString &name = QString("DYNAMIC MEMORY"), QObject *parent = 0);
    ~DynamicMemory();

    QAbstractItemModel *model() const;

    QStringList presetNames() const;

    const QString &name() const { return _name; }
    void setName(const QString &);

    StatusFlags statusFlags() const { return _statusFlags; }
    void setStatusFlags(StatusFlags flags);

    AddStatus newPreset(const QString &);
    DeleteStatus deletePreset(int index);

signals:
    void statusFlagsChanged(StatusFlags);

private:
    void reset();
    void makePreset(bool shouldBeNull, const QString & = QString());
    void destroyPreset(int index);
    DynamicMemoryPreset *preset(int index) const;
    void updatedStatusFlags();

    QString _name;
    QStandardItemModel *_model;
    StatusFlags _statusFlags;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(DynamicMemory::StatusFlags)

#endif // DYNAMICMEMORY_H
