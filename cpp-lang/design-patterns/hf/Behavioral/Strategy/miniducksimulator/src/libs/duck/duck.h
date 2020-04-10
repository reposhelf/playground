#ifndef DUCK_H
#define DUCK_H

class QuackBehavior;
class FlyBehavior;
class Duck
{
public:
    Duck();
    virtual ~Duck();

    virtual void display() const = 0;
    void quack() const;
    void fly() const;
    void swim() const;

    void setQuackBeahvior(QuackBehavior *qb);
    void setFlyBehavior(FlyBehavior *fb);

protected:
    QuackBehavior *m_quackBehavior;
    FlyBehavior *m_flyBehavior;
};

#endif // DUCK_H
