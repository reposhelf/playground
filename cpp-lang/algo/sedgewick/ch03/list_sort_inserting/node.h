#ifndef NODE_H
#define NODE_H

struct Node
{
    Node(int i, Node *n);

    int item;
    Node *next;
};
typedef Node *Link;

#endif // NODE_H