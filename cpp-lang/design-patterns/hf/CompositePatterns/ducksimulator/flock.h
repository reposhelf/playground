#ifndef FLOCK_H
#define FLOCK_H

#include "quackable.h"

#include <vector>

class Flock : public Quackable {
public:
    ~Flock();
    void add(Quackable *quacker);
    void quack() const;
    void registerObserver(Observer *observer);
    void notifyObservers() const;
    std::string name() const;

private:
    std::vector<Quackable*> _quackers;
};

#endif // FLOCK_H
