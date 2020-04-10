#ifndef PIZZA_H
#define PIZZA_H

class Pizza
{
public:
    Pizza();
    virtual ~Pizza();

    virtual void prepare() = 0;
    virtual void bake() = 0;
    virtual void cut() = 0;
    virtual void box() = 0;
};

#endif // PIZZA_H
