#include "node.h"

#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc == 1)
        return 1;
    int n = atoi(argv[1]);
    // create linked list
    Link t = new Node(1, nullptr);
    t->next = t;
    Link x = t;
    for (int i = 2; i <= n; ++i)
        x = (x->next = new Node(i, t));
    // exr 3.23
    // print count of all nodes
    std::cout << nodeCount(t) << std::endl;
    // exr 3.24
    // print count of nodes in a specified range
    std::cout << nodeRangeCount(t, x) << std::endl;
    // create new linked list
    Link newT = new Node(1, nullptr);
    newT->next = newT;
    Link newX = newT;
    for (int i = 2; i <= n; ++i)
        newX = (newX->next = new Node(i, newT));
    // exr 3.25
    // join it with previous linked list
    joinLinkedLists(t, newT);
    printLinkedList(t);
    // exr 3.26
    moveNextNode(t, newT);
    printLinkedList(t);
    // exr 3.27
    Link node = createLinkedList(n);
    if (node)
        printLinkedList(node);
    
    return 0;
}