#ifndef RUBBERDUCK_H
#define RUBBERDUCK_H

#include "quackable.h"

class Observable;
class RubberDuck : public Quackable {
public:
    RubberDuck();
    ~RubberDuck();
    void quack() const;
    void registerObserver(Observer *observer);
    void notifyObservers() const;
    std::string name() const;

private:
    Observable *_observable;
};

#endif // RUBBERDUCK_H
