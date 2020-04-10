#ifndef CHEESE_H
#define CHEESE_H

class Cheese
{
public:
    Cheese();
    virtual ~Cheese() = 0;
};

class MozzarellaCheese : public Cheese
{
public:
    MozzarellaCheese();
    ~MozzarellaCheese();
};

class ReggianoCheese : public Cheese
{
public:
    ReggianoCheese();
    ~ReggianoCheese();
};

#endif // CHEESE_H
