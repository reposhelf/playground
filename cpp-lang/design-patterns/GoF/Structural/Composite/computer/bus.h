#ifndef BUS_H
#define BUS_H

#include "composite_equipment.h"

class Bus : public CompositeEquipment {
public:
    Bus(const char *name);
};

#endif
