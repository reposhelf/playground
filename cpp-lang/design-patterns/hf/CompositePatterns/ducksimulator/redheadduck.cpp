#include "redheadduck.h"
#include "observable.h"

#include <iostream>
using std::cout;
using std::endl;

RedheadDuck::RedheadDuck()
    : _observable(new Observable(this))
{
}

RedheadDuck::~RedheadDuck()
{
    delete _observable;
}

void RedheadDuck::quack() const
{
    cout << "Quack!" << endl;
    notifyObservers();
}

void RedheadDuck::registerObserver(Observer *observer)
{
    _observable->registerObserver(observer);
}

void RedheadDuck::notifyObservers() const
{
    _observable->notifyObservers();
}

std::string RedheadDuck::name() const
{
    return "Redhead Duck";
}
