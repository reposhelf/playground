#include "node.h"

Node::Node()
    : m_item(0),
      m_next(nullptr)
{
}

void Node::setItem(int item)
{
    m_item = item;
}

void Node::setNext(Node *next)
{
    m_next = next;
}
