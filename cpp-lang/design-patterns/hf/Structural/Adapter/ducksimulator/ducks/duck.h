#ifndef DUCK_H
#define DUCK_H

class Duck
{
public:
    Duck();
    virtual ~Duck();

    virtual void quack() const = 0;
    virtual void fly() const = 0;
};

#endif // DUCK_H
