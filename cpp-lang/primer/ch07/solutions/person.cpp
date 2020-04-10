#include "person.h"

Person::Person(const std::string &name, const std::string &address)
    : _name(name),
      _address(address)
{
}

Person::Person(std::istream &is)
{
    is >> *this;
}

void Person::setName(const std::string &name)
{
    _name = name;
}

void Person::setAddress(const std::string &address)
{
    _address = address;
}

std::istream &operator>>(std::istream &is, Person &person)
{
    return (is >> person._name >> person._address);
}

std::ostream &operator<<(std::ostream &os, const Person &person)
{
    return (os << person.name() << " " << person.address());
}
