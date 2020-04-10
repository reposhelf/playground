#ifndef SAUCE_H
#define SAUCE_H

class Sauce
{
public:
    Sauce();
    virtual ~Sauce() = 0;
};

class MarinaraSauce : public Sauce
{
public:
    MarinaraSauce();
    ~MarinaraSauce();
};

class PlumTomatoSauce : public Sauce
{
public:
    PlumTomatoSauce();
    ~PlumTomatoSauce();
};

#endif // SAUCE_H
