/*
 * Exercise 5.17:
 * Write a recursive program that finds the maximum element in a linked list.
 */

#include "chapter05.h"
using namespace std;

int max(Link linkedList)
{
    if (!linkedList)
        return 0;

    if (!linkedList->next)
        return linkedList->item;

    int maxFromLinkedList = max(linkedList->next);
    return (linkedList->item > maxFromLinkedList ? linkedList->item : maxFromLinkedList);
}

void sol_5_17()
{
    Link head = new Node(33, nullptr);
    Link tail = head;
    tail = (tail->next = new Node(45, nullptr));
    tail = (tail->next = new Node(17, nullptr));
    tail = (tail->next = new Node(49, nullptr));
    tail = (tail->next = new Node(11, nullptr));
    tail = (tail->next = new Node(35, nullptr));

    cout << max(head) << endl;
    destroyLinkedList(&head);
}