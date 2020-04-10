/*
 * Exercise 5.14:
 * Write a recursive program that removes the final node of a linked list.
 */

#include <iostream>
using std::cout;
using std::endl;

struct Node
{
    int item;
    Node *next;

    Node(int i, Node *n)
        : item(i), next(n) {}
};
typedef Node *Link;

Link createLinkedList(size_t size, int startValue)
{
    Link head = new Node(startValue, nullptr);
    Link tail = head;

    int nextValue = startValue + 1;
    for (size_t i = 0; i < size - 1; ++i, ++nextValue) {
        tail->next = new Node(nextValue, nullptr);
        tail = tail->next;
    }

    return head;
}

void print(Link list)
{
    while (list) {
        cout << list->item << " ";
        list = list->next;
    }
    cout << endl;
}

void popBack(Link *list)
{
    if (!(*list))
        return;

    if (!(*list)->next) {
        delete *list;
        *list = nullptr;
        return;
    }

    if (!(*list)->next->next) {
        delete (*list)->next;
        (*list)->next = nullptr;
        return;
    }

    popBack(&(*list)->next);
}

int main(int argc, char **argv)
{
    Link list = createLinkedList(10, 1);

    while (list) {
        print(list);
        popBack(&list);
    }

    return 0;
}