#include "josephushelection.h"

struct Node {
    Node(int i, Node *n) {
        item = i;
        next = n;
    }
    int item;
    Node *next;
};
typedef Node *Link;

uint JosephushElection::value(uint m, uint n)
{
    // create linked list
    Link node = new Node(1, Q_NULLPTR);
    node->next = node;
    for (uint i = 2; i <= n; ++i)
        node = (node->next = new Node(i, node->next));
    // calculate
    while (node->next != node) {
        for (uint i = 0; i < m; ++i)
            node = node->next;
        node->next = node->next->next;
    }
    return node->item;
}
