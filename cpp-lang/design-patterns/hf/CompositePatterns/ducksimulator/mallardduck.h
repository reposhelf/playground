#ifndef MALLARDDUCK_H
#define MALLARDDUCK_H

#include "quackable.h"

class Observable;
class MallardDuck : public Quackable {
public:
    MallardDuck();
    ~MallardDuck();
    void quack() const;
    void registerObserver(Observer *observer);
    void notifyObservers()const;
    std::string name() const;

private:
    Observable *_observable;
};

#endif // MALLARDDUCK_H
