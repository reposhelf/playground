#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;
class Observer
{
public:
    virtual ~Observer() = default;
    virtual void update(Subject *subject) = 0;

protected:
    Observer() = default;
};

#endif // OBSERVER_H
