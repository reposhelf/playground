#ifndef MUTEQUACK_H
#define MUTEQUACK_H

#include "quackbehavior.h"

class MuteQuack : public QuackBehavior
{
public:
    MuteQuack();
    ~MuteQuack();

    void quack() const;
};

#endif // MUTEQUACK_H
