#ifndef DYNAMICMEMORYPRESET_H
#define DYNAMICMEMORYPRESET_H

#include <QMetaType>
#include <QString>

class DynamicMemory;
class DynamicMemoryPreset
{
public:
    DynamicMemoryPreset();
    DynamicMemoryPreset(const DynamicMemoryPreset &);
    DynamicMemoryPreset(DynamicMemory *owner);
    ~DynamicMemoryPreset();

    bool isNull() const;

    const QString &name() const;
    void setName(const QString &);

    DynamicMemory *owner() const;
    void setOwner(DynamicMemory *);

private:
    QString _name;
    DynamicMemory *_owner;
};

Q_DECLARE_METATYPE(DynamicMemoryPreset *)

#endif // DYNAMICMEMORYPRESET_H
