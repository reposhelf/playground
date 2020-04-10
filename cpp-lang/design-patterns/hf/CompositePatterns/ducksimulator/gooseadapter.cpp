#include "gooseadapter.h"
#include "observable.h"

GooseAdapter::GooseAdapter(Goose *goose)
    : _goose(goose),
      _observable(new Observable(this))
{
}

GooseAdapter::~GooseAdapter()
{
    delete _goose;
    delete _observable;
}

void GooseAdapter::quack() const
{
    if (_goose) {
        _goose->honk();
        notifyObservers();
    }
}

void GooseAdapter::registerObserver(Observer *observer)
{
    _observable->registerObserver(observer);
}

void GooseAdapter::notifyObservers() const
{
    _observable->notifyObservers();
}

std::string GooseAdapter::name() const
{
    return "Goose Adaptor";
}
