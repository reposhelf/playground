#include "duckfactory.h"
#include "mallardduck.h"
#include "redheadduck.h"
#include "rubberduck.h"
#include "duckcall.h"

Quackable *DuckFactory::createMallardDuck() const
{
    return new MallardDuck;
}

Quackable *DuckFactory::createRedheadDuck() const
{
    return new RedheadDuck;
}

Quackable *DuckFactory::createRubberDuck() const
{
    return new RubberDuck;
}

Quackable *DuckFactory::createDuckCall() const
{
    return new DuckCall;
}
