#ifndef NUMBERED_H
#define NUMBERED_H

#include <cstdlib>

class numbered
{
public:
    numbered();
    numbered(const numbered &);
    size_t mysn() const;
private:
    static size_t counter;
    size_t _mysn;
};

void test_numbered();

#endif