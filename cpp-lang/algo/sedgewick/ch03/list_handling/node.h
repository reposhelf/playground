#ifndef NODE_H
#define NODE_H

struct Node
{
    Node(int i, Node *n);

    int item;
    Node *next;
};
typedef Node *Link;

void printLinkedList(Link node);
int nodeCount(Link node);
Link createLinkedList(int count);
Link reverse(Link x);


#endif // NODE_H