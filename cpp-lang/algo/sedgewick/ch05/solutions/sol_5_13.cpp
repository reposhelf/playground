/*
 * Write a recursive program for the Josephus problem.
 */

#include <cstdlib>
#include <iostream>
using std::cout; using std::endl;

struct node
{
    int item;
    node *next;
    node(int i, node *n)
        : item(i), next(n) {}
};
typedef node *link;

link josephus_problem(link nd, int m)
{
    if (nd == nd->next)
        return nd;

    for (int i = 1; i < m; ++i)
        nd = nd->next;
    link t = nd->next;
    nd->next = nd->next->next;
    delete t;
    return josephus_problem(nd, m);
}

int main(int argc, char **argv)
{
    const int n = std::atoi(argv[1]);
    const int m = std::atoi(argv[2]);

    link nd = new node(1, nullptr);
    nd->next = nd;

    for (int i = 2; i <= n; ++i)
        nd = (nd->next = new node(i, nd->next));

    cout << (nd = josephus_problem(nd, m))->item << endl;

    delete nd;

    return 0;
}