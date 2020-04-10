#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person
{
public:
    Person() = default;
    Person(const std::string &name, const std::string &address);
    Person(std::istream &is);

    std::string name() const { return _name; }
    void setName(const std::string &name);

    std::string address() const { return _address; }
    void setAddress(const std::string &address);

private:
    std::string _name;
    std::string _address;

    friend std::istream &operator>>(std::istream &is, Person &person);
};

std::ostream &operator<<(std::ostream &os, const Person &person);
std::istream &operator>>(std::istream &is, Person &person);

#endif
