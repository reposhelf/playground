#include "turkeyadapter.h"
#include "turkey.h"

#include <iostream>
using namespace std;

TurkeyAdapter::TurkeyAdapter(Turkey *turkey)
    : Duck(),
      m_turkey(turkey)
{
}

TurkeyAdapter::~TurkeyAdapter()
{
}

void TurkeyAdapter::quack() const
{
    m_turkey->gobble();
}

void TurkeyAdapter::fly() const
{
    m_turkey->fly();
}
