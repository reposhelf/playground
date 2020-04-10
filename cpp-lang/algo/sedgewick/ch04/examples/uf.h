/*
 * Program 4.9. Equivalence-relations ADT interface.
 */

#ifndef UF_H
#define UF_H

class UF
{
public:
    UF(int N);
    int find(int p, int q);
    void unite(int p, int q);

private:
    int find(int x);

    int *_id;
    int *_sz;
};

#endif // UF_H
