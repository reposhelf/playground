#ifndef FLYBEHAVIOR_H
#define FLYBEHAVIOR_H


class FlyBehavior
{
public:
    FlyBehavior();
    virtual ~FlyBehavior();

    virtual void fly() const = 0;
};

#endif // FLYBEHAVIOR_H
