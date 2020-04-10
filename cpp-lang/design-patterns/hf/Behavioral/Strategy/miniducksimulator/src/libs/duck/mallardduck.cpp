#include "mallardduck.h"
#include "quack.h"
#include "flywithwings.h"

#include <iostream>

MallardDuck::MallardDuck()
    : Duck()
{
    m_quackBehavior = new Quack;
    m_flyBehavior = new FlyWithWings;
}

MallardDuck::~MallardDuck()
{

}

void MallardDuck::display() const
{
    std::cout << "I'm a real Mallard duck!" << std::endl;
}
