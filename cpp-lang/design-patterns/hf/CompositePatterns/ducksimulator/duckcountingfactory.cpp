#include "duckcountingfactory.h"
#include "quackcounter.h"
#include "mallardduck.h"
#include "redheadduck.h"
#include "rubberduck.h"
#include "duckcall.h"

Quackable *DuckCountingFactory::createMallardDuck() const
{
    return new QuackCounter(new MallardDuck);
}

Quackable *DuckCountingFactory::createRedheadDuck() const
{
    return new QuackCounter(new RedheadDuck);
}

Quackable *DuckCountingFactory::createRubberDuck() const
{
    return new QuackCounter(new RubberDuck);
}

Quackable *DuckCountingFactory::createDuckCall() const
{
    return new QuackCounter(new DuckCall);
}
