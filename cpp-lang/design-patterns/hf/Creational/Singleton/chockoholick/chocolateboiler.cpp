#include "chocolateboiler.h"

#include <iostream>
using namespace std;

void ChocolateBoiler::fill()
{
    if (instance()->m_isEmpty) {
        instance()->m_isEmpty = false;
        instance()->m_isBoiled = false;

        cout << "FILLING" << endl;
    }
}

void ChocolateBoiler::boil()
{
    if (!instance()->m_isEmpty && !instance()->m_isBoiled) {
        instance()->m_isBoiled = true;

        cout << "BOILING" << endl;
    }
}

void ChocolateBoiler::drain()
{
    if (!instance()->m_isEmpty && instance()->m_isBoiled) {
        instance()->m_isBoiled = false;
        instance()->m_isEmpty = true;

        cout << "DRAINING" << endl;
    }
}

ChocolateBoiler::ChocolateBoiler()
    : m_isEmpty(true),
      m_isBoiled(false)
{
}

ChocolateBoiler::ChocolateBoiler(const ChocolateBoiler &)
{
}

ChocolateBoiler &ChocolateBoiler::operator=(const ChocolateBoiler &)
{
    return *this;
}

ChocolateBoiler::~ChocolateBoiler()
{
}

ChocolateBoiler *ChocolateBoiler::instance()
{
    static ChocolateBoiler cb;
    return &cb;
}
