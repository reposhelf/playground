#include "quackcounter.h"

int QuackCounter::_numberOfQuacks = 0;

QuackCounter::QuackCounter(Quackable *duck)
    : _duck(duck)
{
}

QuackCounter::~QuackCounter()
{
    delete _duck;
}

void QuackCounter::quack() const
{
    if (_duck) {
        _duck->quack();
        ++_numberOfQuacks;
    }
}

void QuackCounter::registerObserver(Observer *observer)
{
    _duck->registerObserver(observer);
}

void QuackCounter::notifyObservers() const
{
    _duck->notifyObservers();
}

std::string QuackCounter::name() const
{
    return _duck->name();
}

int QuackCounter::numberOfQuacks()
{
    return _numberOfQuacks;
}

