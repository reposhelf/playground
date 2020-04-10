#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Node();

    int item() const { return m_item; }
    void setItem(int item);

    Node *next() const { return m_next; }
    void setNext(Node *next);

private:
    int m_item;
    Node *m_next;
};

#endif // NODE_H
