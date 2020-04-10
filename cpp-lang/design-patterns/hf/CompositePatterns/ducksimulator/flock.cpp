#include "flock.h"

Flock::~Flock()
{
    for (Quackable *q : _quackers)
        delete q;
    _quackers.clear();
}

void Flock::add(Quackable *quacker)
{
    _quackers.push_back(quacker);
}

void Flock::quack() const
{
    for (Quackable *q : _quackers)
        q->quack();
}

void Flock::registerObserver(Observer *observer)
{
    for (Quackable *q : _quackers)
        q->registerObserver(observer);
}

void Flock::notifyObservers() const
{
    // Nothing to do
}

std::string Flock::name() const
{
    return std::string();
}
