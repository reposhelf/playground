#ifndef GOOSEADAPTER_H
#define GOOSEADAPTER_H

#include "quackable.h"
#include "goose.h"

class Observable;
class GooseAdapter : public Quackable {
public:
    GooseAdapter(Goose *goose);
    ~GooseAdapter();
    void quack() const;
    void registerObserver(Observer *observer);
    void notifyObservers() const;
    std::string name() const;

private:
    Goose *_goose;
    Observable *_observable;

};

#endif // GOOSEADAPTER_H
