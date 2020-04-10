#ifndef QUACKCOUNTER_H
#define QUACKCOUNTER_H

#include "quackable.h"

class QuackCounter : public Quackable {
public:
    QuackCounter(Quackable *duck);
    ~QuackCounter();

    void quack() const;
    void registerObserver(Observer *observer);
    void notifyObservers() const;
    std::string name() const;
    static int numberOfQuacks();

private:
    Quackable *_duck;
    static int _numberOfQuacks;
};

#endif // QUACKCOUNTER_H
