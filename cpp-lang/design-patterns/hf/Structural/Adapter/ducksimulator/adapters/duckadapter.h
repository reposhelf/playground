#ifndef DUCKADAPTER_H
#define DUCKADAPTER_H

#include "turkey.h"

class Duck;
class DuckAdapter : public Turkey
{
public:
    DuckAdapter(Duck *duck);
    ~DuckAdapter();

    void gobble() const;
    void fly() const;

private:
    Duck *m_duck;
};

#endif // DUCKADAPTER_H
