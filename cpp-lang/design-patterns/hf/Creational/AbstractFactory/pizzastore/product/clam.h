#ifndef CLAM_H
#define CLAM_H

class Clam
{
public:
    Clam();
    virtual ~Clam() = 0;
};

class FreshClam : public Clam
{
public:
    FreshClam();
    ~FreshClam();
};

class FrozenClam : public Clam
{
public:
    FrozenClam();
    ~FrozenClam();
};

#endif // CLAM_H
