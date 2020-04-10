#ifndef COFFEE_H
#define COFFEE_H

#include "caffeinebeverage.h"

#include <string>

class Coffee : public CaffeineBeverage
{
public:
    Coffee();

    void brew() const;
    void addCondiments() const;
    bool customerWantsCondiments() const;

    std::string askAboutCondiments() const;
};

#endif // COFFEE_H
