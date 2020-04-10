#ifndef CHASSIS_H
#define CHASSIS_H

#include "composite_equipment.h"

class Chassis : public CompositeEquipment {
public:
    Chassis(const char *name);
};

#endif
