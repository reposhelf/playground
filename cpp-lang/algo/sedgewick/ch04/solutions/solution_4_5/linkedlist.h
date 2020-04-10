#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>

class Node;
class LinkedList
{
public:
    LinkedList(size_t size);
    ~LinkedList();

    Node *newNode(int item);
    void deleteNode(Node *node);
    void insert(Node *before, Node *node);
    Node *remove(Node *node);
    int item(Node *node) const;
    Node *next(Node *node) const;

private:
    size_t m_size;
    Node *m_freeList;
};

#endif // LINKEDLIST_H
