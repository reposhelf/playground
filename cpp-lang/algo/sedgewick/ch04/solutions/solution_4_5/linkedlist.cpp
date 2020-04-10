#include "linkedlist.h"
#include "node.h"

LinkedList::LinkedList(size_t size)
    : m_size(size),
      m_freeList(nullptr)
{
    m_freeList = new Node[m_size + 1];
    for (size_t i = 0; i < m_size; ++i)
        m_freeList[i].setNext(&m_freeList[i + 1]);
    m_freeList[m_size].setNext(nullptr);
}

LinkedList::~LinkedList()
{
    delete[] m_freeList;
}

Node *LinkedList::newNode(int item)
{
    Node *x = remove(m_freeList);
    x->setItem(item);
    x->setNext(x);
    return x;
}

void LinkedList::deleteNode(Node *node)
{
    insert(m_freeList, node);
}

void LinkedList::insert(Node *before, Node *node)
{
    node->setNext(before->next());
    before->setNext(node);
}

Node *LinkedList::remove(Node *node)
{
    Node *t = node->next();
    node->setNext(t->next());
    return t;
}

int LinkedList::item(Node *node) const
{
    return node->item();
}

Node *LinkedList::next(Node *node) const
{
    return node->next();
}
