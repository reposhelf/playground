#include "subject.h"
#include "observer.h"

void Subject::attach(Observer *observer)
{
    _observers.push_back(observer);
}

void Subject::detach(Observer *observer)
{
    _observers.remove(observer);
}

void Subject::notify()
{
    for (auto observer : _observers)
        observer->update(this);
}
