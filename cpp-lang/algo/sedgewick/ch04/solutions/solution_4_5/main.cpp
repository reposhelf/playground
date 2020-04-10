/*
 * 4.4
 * Write a client program that takes an integer N from the command line, and fills an array with N
 * points, no two of which are equal. Use the overloaded== operator described in the text to test
 * equality., to use it, then switch to an array-based implementation (see  4.5 Convert the
 * list-processing interface in Section 3.4 Exercise 3.52).  (Program 3.12) into a class-based ADT
 * implementation, using a linked-list representation as in Program 3.14. Test your interface by
 * modifying the client program, Program 3.13
 */
#include "linkedlist.h"
#include "node.h"

#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;

int main(int /*argc*/, char **argv)
{
    const size_t N = atoi(argv[1]);
    const size_t M = atoi(argv[2]);

    LinkedList list(N);

    Node *t, *x;
    size_t i;
    for (i = 2, x = list.newNode(1); i <= N; ++i) {
        t = list.newNode(i);
        list.insert(x, t);
        x = t;
    }
    while (x != list.next(x)) {
        for (i = 1; i < M; ++i)
            x = list.next(x);
        list.deleteNode(list.remove(x));
    }
    cout << list.item(x) << endl;

    return 0;
}
