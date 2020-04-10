#ifndef TURKEYADAPTER_H
#define TURKEYADAPTER_H

#include "duck.h"

class Turkey;
class TurkeyAdapter : public Duck
{
public:
    TurkeyAdapter(Turkey *turkey);
    ~TurkeyAdapter();

    void quack() const;
    void fly() const;

private:
    Turkey *m_turkey;
};

#endif // TURKEYADAPTER_H
