#ifndef TEA_H
#define TEA_H

#include "caffeinebeverage.h"

#include <string>

class Tea : public CaffeineBeverage
{
public:
    Tea();

    void brew() const;
    void addCondiments() const;
    bool customerWantsCondiments() const;

    std::string askAboutCondiments() const;
};

#endif // TEA_H
