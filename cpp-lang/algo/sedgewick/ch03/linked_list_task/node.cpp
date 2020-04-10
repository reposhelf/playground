#include "node.h"

#include <iostream>

Node::Node(int i, Node *n)
{
    item = i;
    next = n;
}

void printLinkedList(Link node)
{
    int linkedListSize = nodeCount(node);
    for (int i = 0; i < linkedListSize; ++i, node = node->next)
        std::cout << node->item << " ";
    std::cout << std::endl;
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

int nodeRangeCount(Link begin, Link end)
{
    int count = 0;
    for (Link node_iter = begin;
         node_iter->next != end;
         node_iter = node_iter->next) {
        ++count;
    }
    return count;
}

void joinLinkedLists(Link x, Link t)
{
    // find last node by t
    int linkedListSize = nodeCount(t);
    for (int i = 1; i < linkedListSize; ++i)
        t = t->next;

    Link temp = t->next; // store first node of t
    t->next = x->next;   // connect last node of t and second node of x
    x->next = temp;      // connect first node of x and first node of t
}

void moveNextNode(Link x, Link t)
{
    Link temp = t->next;      // store node t->next
    t->next = t->next->next;  // remove node t->next
    temp->next = x->next;     // insert...
    x->next = temp;           // ...removed node t->next
}

Link createLinkedList(int count)
{
    if (count == 0)
        return nullptr;
    Link node = new Node(1, nullptr);
    node->next = node;
    for (int i = 2; i <= count; ++i)
        node = (node->next = new Node(i, node->next));
    return node;
}