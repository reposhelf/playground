#include "dynamicmemorypreset.h"

DynamicMemoryPreset::DynamicMemoryPreset()
    : _name(QStringLiteral("None")),
      _owner(0)
{
    // TODO: registers bank is empty
}

DynamicMemoryPreset::DynamicMemoryPreset(const DynamicMemoryPreset &other)
    : _name(other._name),
      _owner(other._owner)
{
    // TODO: owner set free registers bank to preset
}

DynamicMemoryPreset::DynamicMemoryPreset(DynamicMemory *owner)
    : _owner(owner)
{
    // TODO: owner set free registers bank to preset
}

DynamicMemoryPreset::~DynamicMemoryPreset()
{
    // TODO; owner must return registers bank to itself
}

bool DynamicMemoryPreset::isNull() const
{
    return (_owner == 0);
}

const QString &DynamicMemoryPreset::name() const
{
    return _name;
}

void DynamicMemoryPreset::setName(const QString &n)
{
    if (name() == n)
        return;
    _name = n;
}

DynamicMemory *DynamicMemoryPreset::owner() const
{
    return _owner;
}

void DynamicMemoryPreset::setOwner(DynamicMemory *o)
{
    if (owner() == o)
        return;
    _owner = o;
    // TODO: owner set free registers bank to preset
}
