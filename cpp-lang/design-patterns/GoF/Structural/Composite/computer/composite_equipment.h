#ifndef COMPOSITE_EQUIPMENT_H
#define COMPOSITE_EQUIPMENT_H

#include <list>

#include "equipment.h"

class CompositeEquipment : public Equipment {
public:
    virtual ~CompositeEquipment() override;

    virtual double power() override;
    virtual double net_price() override;
    virtual double discount_price() override;

    virtual void add(Equipment *equipment) override;
    virtual void remove(Equipment *equipment) override;

protected:
    CompositeEquipment(const char *name);

private:
    std::list<Equipment*> equipment_;
};

#endif
