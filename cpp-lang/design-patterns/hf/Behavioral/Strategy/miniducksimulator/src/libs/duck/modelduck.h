#ifndef MODELDUCK_H
#define MODELDUCK_H

#include "duck.h"

class ModelDuck : public Duck
{
public:
    ModelDuck();
    ~ModelDuck();

    void display() const;
};

#endif // MODELDUCK_H
