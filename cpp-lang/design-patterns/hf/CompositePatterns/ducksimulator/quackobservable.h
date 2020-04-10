#ifndef QUACKOBSERVABLE_H
#define QUACKOBSERVABLE_H

#include <string>

class Observer;
class QuackObservable {
public:
    virtual ~QuackObservable() {}
    virtual void registerObserver(Observer *observer) = 0;
    virtual void notifyObservers() const = 0;
    virtual std::string name() const = 0;
};

#endif // QUACKOBSERVABLE_H
