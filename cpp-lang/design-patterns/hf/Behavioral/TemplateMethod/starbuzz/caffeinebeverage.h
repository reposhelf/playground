#ifndef CAFFEINEBEVERAGE_H
#define CAFFEINEBEVERAGE_H

class CaffeineBeverage
{
public:
    CaffeineBeverage();

    // template method
    virtual void prepareRecipe() const final;
    // steps of algorithm
    virtual void boilWater() const final;
    virtual void pourInCup() const final;
    virtual void brew() const = 0;
    virtual void addCondiments() const = 0;
    // hook
    virtual bool customerWantsCondiments() const;
};

#endif // CAFFEINEBEVERAGE_H
