#include "quackologist.h"
#include "quackobservable.h"

#include <iostream>
using std::cout;
using std::endl;

Quackologist::Quackologist()
{
}

void Quackologist::update(QuackObservable *duck)
{
    cout << "Quackologist: " << duck->name() << " just quacked." << endl;
}
