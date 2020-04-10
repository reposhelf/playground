#ifndef OBSERVER_H
#define OBSERVER_H

class QuackObservable;
class Observer {
public:
    virtual void update(QuackObservable *duck) = 0;
};

#endif // OBSERVER_H
