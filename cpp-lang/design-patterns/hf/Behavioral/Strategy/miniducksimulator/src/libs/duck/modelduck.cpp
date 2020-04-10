#include "modelduck.h"
#include "quack.h"
#include "flynoway.h"

#include <iostream>

ModelDuck::ModelDuck()
    : Duck()
{
    m_quackBehavior = new Quack();
    m_flyBehavior = new FlyNoWay();
}

ModelDuck::~ModelDuck()
{

}

void ModelDuck::display() const
{
    std::cout << "I'm a Model duck!" << std::endl;
}
