#ifndef DUCKCOUNTINGFACTORY_H
#define DUCKCOUNTINGFACTORY_H

#include "abstractduckfactory.h"

class DuckCountingFactory : public AbstractDuckFactory {
public:
    ~DuckCountingFactory() {}
    Quackable *createMallardDuck() const;
    Quackable *createRedheadDuck() const;
    Quackable *createRubberDuck() const;
    Quackable *createDuckCall() const;
};

#endif // DUCKCOUNTINGFACTORY_H
