#ifndef STRUCTX_H
#define STRUCTX_H

struct X
{
    X();
    X(const X&);
    ~X();
    X &operator=(const X&);
};

void test_struct_x();

#endif