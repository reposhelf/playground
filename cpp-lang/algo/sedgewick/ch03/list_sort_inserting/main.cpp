#include "node.h"

#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>

int main(int argc, char *argv[])
{
    if (argc == 1) {
        cout << "error: expected one parameter" << endl;
        return 1;
    }
    const int node_count = atoi(argv[1]);

    Node head_a(0, nullptr);
    Link a = &head_a;
    Link t = a;
    for (int i = 0; i < node_count; ++i)
        t = (t->next = new Node(rand() & 1000, nullptr));

    Node head_b(0, nullptr);
    Link b = &head_b;
    Link u;
    Link x;

    // sort
    for (t = a->next; t != nullptr; t = u) {
        u = t->next;
        for (x = b; x->next != nullptr; x = x->next) {
            if (x->next->item > t->item)
                break;
        }
        t->next = x->next;
        x->next = t;
    }
    // print
    for (Link i = b->next; i != nullptr; i = i->next)
        cout << i->item << " ";
    cout << endl;
    return 0;
}