#include "node.h"

#include <iostream>
using std::cout;
using std::endl;

Node::Node(int i, Node *n)
{
    item = i;
    next = n;
}

void printLinkedList(Link node)
{
    if (!node)
        return;
    int linkedListSize = nodeCount(node);
    for (int i = 0; i < linkedListSize; ++i, node = node->next)
        cout << node->item << " ";
    cout << endl;
}

int nodeCount(Link node)
{
    int count = 1;
    for (Link node_iter = node;
         node_iter->next != node;
         node_iter = node_iter->next) {
        ++count;
    }
    return count;
}

Link createLinkedList(int count)
{
    if (count == 0)
        return nullptr;
    Link node = new Node(1, nullptr);
    node->next = node;
    for (int i = 2; i <= count; ++i)
        node = (node->next = new Node(i, node->next));
    return node->next;
}

Link reverse(Link x)
{
    if (!x)
        return nullptr;
    Link t, y = x, r = nullptr;
    while (y) {
        t = y->next;
        y->next = r;
        r = y;
        y = t;
    }
    return r->next;
}