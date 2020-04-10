#ifndef SQUEAK_H
#define SQUEAK_H

#include "quackbehavior.h"

class Squeak : public QuackBehavior
{
public:
    Squeak();
    ~Squeak();

    void quack() const;
};

#endif // SQUEAK_H
