#ifndef ABSTRACTDUCKFACTORY_H
#define ABSTRACTDUCKFACTORY_H

class Quackable;
class AbstractDuckFactory {
public:
    virtual ~AbstractDuckFactory() {}
    virtual Quackable *createMallardDuck() const = 0;
    virtual Quackable *createRedheadDuck() const = 0;
    virtual Quackable *createRubberDuck() const = 0;
    virtual Quackable *createDuckCall() const = 0;
};

#endif // ABSTRACTDUCKFACTORY_H
