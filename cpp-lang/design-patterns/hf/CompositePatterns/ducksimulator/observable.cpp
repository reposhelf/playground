#include "observable.h"
#include "observer.h"

Observable::Observable(QuackObservable *duck)
    : _duck(duck)
{
}

Observable::~Observable()
{
}

void Observable::registerObserver(Observer *observer)
{
    _observers.push_back(observer);
}

void Observable::notifyObservers() const
{
    for (Observer *observer : _observers)
        observer->update(_duck);
}

std::string Observable::name() const
{
    return std::string();
}
