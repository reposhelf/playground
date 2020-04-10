#include "mallardduck.h"
#include "observable.h"

#include <iostream>
using std::cout;
using std::endl;

MallardDuck::MallardDuck()
    : _observable(new Observable(this))
{
}

MallardDuck::~MallardDuck()
{
    delete _observable;
}

void MallardDuck::quack() const
{
    cout << "Quack!" << endl;
    notifyObservers();
}

void MallardDuck::registerObserver(Observer *observer)
{
    _observable->registerObserver(observer);
}

void MallardDuck::notifyObservers() const
{
    _observable->notifyObservers();
}

std::string MallardDuck::name() const
{
    return "Mallard Duck";
}
