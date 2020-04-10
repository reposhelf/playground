#include "duck.h"
#include "quackbehavior.h"
#include "flybehavior.h"

#include <iostream>

Duck::Duck()
    : m_quackBehavior(0),
      m_flyBehavior(0)
{
}

Duck::~Duck()
{
    delete m_quackBehavior;
    delete m_flyBehavior;
}

void Duck::quack() const
{
    m_quackBehavior->quack();
}

void Duck::fly() const
{
    m_flyBehavior->fly();
}

void Duck::swim() const
{
    std::cout << "All ducks float, even decoys!" << std::endl;
}

void Duck::setQuackBeahvior(QuackBehavior *qb)
{
    if (!qb)
        return;

    delete m_quackBehavior;
    m_quackBehavior = qb;
}

void Duck::setFlyBehavior(FlyBehavior *fb)
{
    if (!fb)
        return;

    delete m_flyBehavior;
    m_flyBehavior = fb;
}
