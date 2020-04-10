#ifndef MALLARDDUCK_H
#define MALLARDDUCK_H

#include "duck.h"

class MallardDuck : public Duck
{
public:
    MallardDuck();
    ~MallardDuck();

    void display() const;
};

#endif // MALLARDDUCK_H
