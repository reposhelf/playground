#ifndef PEPPERONI_H
#define PEPPERONI_H

class Pepperoni
{
public:
    Pepperoni();
    virtual ~Pepperoni() = 0;
};

class SlicedPepperoni : public Pepperoni
{
public:
    SlicedPepperoni();
    ~SlicedPepperoni();
};

#endif // PEPPERONI_H
