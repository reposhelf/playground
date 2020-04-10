#ifndef MALLARDDUCK_H
#define MALLARDDUCK_H

#include "duck.h"

class MallardDuck : public Duck
{
public:
    MallardDuck();
    ~MallardDuck();

    void quack() const;
    void fly() const;
};

#endif // MALLARDDUCK_H
