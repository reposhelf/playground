#include "duckcall.h"
#include "observable.h"

#include <iostream>
using std::cout;
using std::endl;

DuckCall::DuckCall()
    : _observable(new Observable(this))
{
}

DuckCall::~DuckCall()
{
    delete _observable;
}

void DuckCall::quack() const
{
    std::cout << "Kwack!" << std::endl;
    notifyObservers();
}

void DuckCall::registerObserver(Observer *observer)
{
    _observable->registerObserver(observer);
}

void DuckCall::notifyObservers() const
{
    _observable->notifyObservers();
}

std::string DuckCall::name() const
{
    return "Duck Call";
}
