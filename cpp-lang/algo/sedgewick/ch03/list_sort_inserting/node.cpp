#include "node.h"

#include <iostream>

Node::Node(int i, Node *n)
{
    item = i;
    next = n;
}