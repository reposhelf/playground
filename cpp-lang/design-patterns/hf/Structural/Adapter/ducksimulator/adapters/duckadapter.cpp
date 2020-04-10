#include "duckadapter.h"
#include "duck.h"

#include <cstdlib>
#include <ctime>

DuckAdapter::DuckAdapter(Duck *duck)
    : Turkey(),
      m_duck(duck)
{
}

DuckAdapter::~DuckAdapter()
{
}

void DuckAdapter::gobble() const
{
    m_duck->quack();
}
#include <iostream>
void DuckAdapter::fly() const
{
    srand(time(0));
    if ((rand() % 5) == 0)
    {
        m_duck->fly();
    }
}
