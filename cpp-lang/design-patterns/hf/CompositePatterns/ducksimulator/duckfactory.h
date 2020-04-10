#ifndef DUCKFACTORY_H
#define DUCKFACTORY_H

#include "abstractduckfactory.h"

class DuckFactory : public AbstractDuckFactory {
    ~DuckFactory() {}
    Quackable *createMallardDuck() const;
    Quackable *createRedheadDuck() const;
    Quackable *createRubberDuck() const;
    Quackable *createDuckCall() const;
};

#endif // DUCKFACTORY_H
