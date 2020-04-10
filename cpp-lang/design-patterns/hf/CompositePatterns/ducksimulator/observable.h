#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "quackobservable.h"

#include <list>

class Observer;
class Observable : public QuackObservable {
public:
    Observable(QuackObservable *duck);
    ~Observable();
    void registerObserver(Observer *observer);
    void notifyObservers() const;
    std::string name() const;

private:
    QuackObservable *_duck;
    std::list<Observer *> _observers;
};

#endif // OBSERVABLE_H
