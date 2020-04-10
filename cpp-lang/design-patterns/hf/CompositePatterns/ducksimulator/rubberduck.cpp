#include "rubberduck.h"
#include "observable.h"

#include <iostream>
using std::cout;
using std::endl;

RubberDuck::RubberDuck()
    : _observable(new Observable(this))
{
}

RubberDuck::~RubberDuck()
{
    delete _observable;
}

void RubberDuck::quack() const
{
    cout << "Squeak!" << endl;
    notifyObservers();
}

void RubberDuck::registerObserver(Observer *observer)
{
    _observable->registerObserver(observer);
}

void RubberDuck::notifyObservers() const
{
    _observable->notifyObservers();
}

std::string RubberDuck::name() const
{
    return "Rubber Duck";
}
