#ifndef VEGGIE_H
#define VEGGIE_H

class Veggie
{
public:
    Veggie();
    virtual ~Veggie() = 0;
};

class Garlic : public Veggie
{
public:
    Garlic();
    ~Garlic();
};

class Onion : public Veggie
{
public:
    Onion();
    ~Onion();
};

class Mushroom : public Veggie
{
public:
    Mushroom();
    ~Mushroom();
};

class RedPepper : public Veggie
{
public:
    RedPepper();
    ~RedPepper();
};

class BlackOlives : public Veggie
{
public:
    BlackOlives();
    ~BlackOlives();
};

class Spinach : public Veggie
{
public:
    Spinach();
    ~Spinach();
};

class EggPlant : public Veggie
{
public:
    EggPlant();
    ~EggPlant();
};

#endif // VEGGIE_H
