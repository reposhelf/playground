#ifndef DUCKCALL_H
#define DUCKCALL_H

#include "quackable.h"

#include <iostream>

class Observable;
class DuckCall : public Quackable {
public:
    DuckCall();
    ~DuckCall();
    void quack() const;
    void registerObserver(Observer *observer);
    void notifyObservers() const;
    std::string name() const;

private:
    Observable *_observable;
};

#endif // DUCKCALL_H
