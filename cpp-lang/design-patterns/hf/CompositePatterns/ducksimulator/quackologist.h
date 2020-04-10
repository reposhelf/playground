#ifndef QUACKOLOGIST_H
#define QUACKOLOGIST_H

#include "observer.h"

class Quackologist : public Observer
{
public:
    Quackologist();
    void update(QuackObservable *duck);
};

#endif // QUACKOLOGIST_H
