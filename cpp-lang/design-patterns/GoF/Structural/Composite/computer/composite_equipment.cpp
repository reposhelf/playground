#include "composite_equipment.h"

CompositeEquipment::~CompositeEquipment() {
    for (auto e : equipment_)
        delete e;
}

double CompositeEquipment::power() {
    double total = Equipment::power();
    for (auto e : equipment_)
        total += e->power();
    return total;
}

double CompositeEquipment::net_price() {
    double total = Equipment::net_price();
    for (auto e : equipment_)
        total += e->net_price();
    return total;
}

double CompositeEquipment::discount_price() {
    double total = Equipment::discount_price();
    for (auto e : equipment_)
        total += e->discount_price();
    return total;
}

void CompositeEquipment::add(Equipment *equipment) {
    equipment_.push_back(equipment);
}

void CompositeEquipment::remove(Equipment *equipment) {
    equipment_.remove(equipment);
    delete equipment;
}

CompositeEquipment::CompositeEquipment(const char *name)
    : Equipment(name) {
    // Empty
}
