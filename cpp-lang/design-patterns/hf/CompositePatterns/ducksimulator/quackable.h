#ifndef QUACKABLE_H
#define QUACKABLE_H

#include "quackobservable.h"

class Quackable : public QuackObservable {
public:
    virtual ~Quackable() {}
    virtual void quack() const = 0;
};

#endif // QUACKABLE_H
