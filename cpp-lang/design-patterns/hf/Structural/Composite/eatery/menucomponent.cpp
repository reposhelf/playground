#include "menucomponent.h"

#include <stdexcept>

MenuComponent::MenuComponent()
{
}

MenuComponent::~MenuComponent()
{
}

std::string MenuComponent::getName() const
{
    throw std::runtime_error("unsupported operation exception");
}

std::string MenuComponent::getDescription() const
{
    throw std::runtime_error("unsupported operation exception");
}

bool MenuComponent::isVegetarian() const
{
    throw std::runtime_error("unsupported operation exception");
}

float MenuComponent::getPrice() const
{
    throw std::runtime_error("unsupported operation exception");
}

void MenuComponent::add(MenuComponent *)
{
    throw std::runtime_error("unsupported operation exception");
}

void MenuComponent::remove(MenuComponent *)
{
    throw std::runtime_error("unsupported operation exception");
}

MenuComponent *MenuComponent::getChild(size_t) const
{
    throw std::runtime_error("unsupported operation exception");
}

void MenuComponent::print() const
{
    throw std::runtime_error("unsupported operation exception");
}
