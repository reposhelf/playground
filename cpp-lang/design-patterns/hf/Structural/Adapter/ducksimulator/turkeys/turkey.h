#ifndef TURKEY_H
#define TURKEY_H

class Turkey
{
public:
    Turkey();
    virtual ~Turkey();

    virtual void gobble() const = 0;
    virtual void fly() const = 0;
};

#endif // TURKEY_H
