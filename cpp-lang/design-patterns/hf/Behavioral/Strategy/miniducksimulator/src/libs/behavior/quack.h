#ifndef QUACK_H
#define QUACK_H

#include "quackbehavior.h"

class Quack : public QuackBehavior
{
public:
    Quack();
    ~Quack();

    void quack() const;
};

#endif // QUACK_H
