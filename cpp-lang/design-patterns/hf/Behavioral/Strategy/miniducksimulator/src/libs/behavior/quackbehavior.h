#ifndef QUACKBEHAVIOR_H
#define QUACKBEHAVIOR_H


class QuackBehavior
{
public:
    QuackBehavior();
    virtual ~QuackBehavior();

    virtual void quack() const = 0;
};

#endif // QUACKBEHAVIOR_H
