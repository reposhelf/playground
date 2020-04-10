#ifndef REDHEADDUCK_H
#define REDHEADDUCK_H

#include "quackable.h"

class Observable;
class RedheadDuck : public Quackable {
public:
    RedheadDuck();
    ~RedheadDuck();
    void quack() const;
    void registerObserver(Observer *observer);
    void notifyObservers() const;
    std::string name() const;

private:
    Observable *_observable;
};

#endif // REDHEADDUCK_H
