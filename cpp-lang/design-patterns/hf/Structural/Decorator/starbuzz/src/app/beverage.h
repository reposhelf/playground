#ifndef BEVERAGE_H
#define BEVERAGE_H

#include <string>

class Beverage
{
public:
    Beverage() : _description("Unknown Beverage") {}
    virtual ~Beverage() {}

    std::string description() const { return _description; }
    virtual double cost() const = 0;

protected:
    std::string _description;
};

#endif // BEVERAGE_H
