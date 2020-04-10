#ifndef SUBJECT_H
#define SUBJECT_H

#include <list>

class Observer;

class Subject
{
public:
    virtual ~Subject() = default;
    virtual void attach(Observer *observer);
    virtual void detach(Observer *observer);
    virtual void notify();

protected:
    Subject() = default;

private:
    std::list<Observer *> _observers;
};

#endif // SUBJECT_H
