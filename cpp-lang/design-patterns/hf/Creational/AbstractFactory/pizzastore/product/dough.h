#ifndef DOUGH_H
#define DOUGH_H

class Dough
{
public:
    Dough();
    virtual ~Dough() = 0;
};

class ThickCrustDough : public Dough
{
public:
    ThickCrustDough();
    ~ThickCrustDough();
};

class ThinCrustDough : public Dough
{
public:
    ThinCrustDough();
    ~ThinCrustDough();
};

#endif // DOUGH_H
