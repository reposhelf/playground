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

// exr 3.23
int nodeCount(Link node);
// exr 3.24
int nodeRangeCount(Link begin, Link end);
// exr 3.25
void joinLinkedLists(Link t, Link x);
// exr 3.26
void moveNextNode(Link x, Link t);
// exr 3.27
Link createLinkedList(int count);


#endif // NODE_H