#include "list.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
using std::cout;
using std::endl;

Link createRandomList(int length)
{
    auto list = new Node(0, nullptr);
    auto t = list;
    srand(time(0));
    for (int i = 1; i <= length; ++i)
        t = (t->next = new Node(rand() % 100, nullptr));
    return list;
}

Link createSortedList(int length)
{
    auto list = new Node(0, nullptr);
    auto t = list;
    srand(time(0));
    for (int i = 1; i <= length; ++i)
        t = (t->next = new Node(i, nullptr));
    return list;
}

void display(const Link list)
{
    for (auto t = list->next; t != nullptr; t = t->next)
        cout << t->item << " ";
    cout << endl;
}

/*
 * Exercise 3.33.
 * Write a function that moves the
 * largest item on a given list to
 * be the final node on the list.
 */
void moveLargestToEnd(const Link list)
{
    auto iterator = list->next;
    auto greatestNode = list->next;
    auto prevGreatestNode = list;

    while (iterator->next) {
        if (iterator->next->item > greatestNode->item) {
            greatestNode = iterator->next;
            prevGreatestNode = iterator;
        }
        iterator = iterator->next;
    }

    if (greatestNode->next) {
        prevGreatestNode->next = prevGreatestNode->next->next;
        greatestNode->next = iterator->next;
        iterator->next = greatestNode;
    }
}

/*
 * Exercise 3.34.
 * Write a function that moves the
 * smallest item on a given list to
 * be the first node on the list.
 */
 void moveSmallestToBegin(const Link list)
 {
    if (!list->next)
        return;

    auto iterator = list->next;
    auto smallestNode = list->next;
    auto prevSmallestNode = list;

    while (iterator->next) {
        if (iterator->next->item < smallestNode->item) {
            smallestNode = iterator->next;
            prevSmallestNode = iterator;
        }
        iterator = iterator->next;
    }

    prevSmallestNode->next = prevSmallestNode->next->next;
    smallestNode->next = list->next;
    list->next = smallestNode;
 }

  /*
  * Exercise 3.35.
  * Write a function that rearranges
  * a linked list to put the nodes in
  * even positions of the nodes after
  * the nodes in odd positions in the
  * list, preserving the relative order
  * of both the evens and the odds.
  */
void separateEvensAndOdds(const Link list)
{
    if (!list->next)
        return;

    auto evens = list->next;
    auto odds = evens->next;
    auto oddsTail = odds;

    while (evens->next) {
        if (evens->next != odds) {
            oddsTail->next = evens->next;
            oddsTail = oddsTail->next;
        }
        evens->next = evens->next->next;

        if (evens->next)
            evens = evens->next;
    }

    oddsTail->next = nullptr;
    evens->next = odds;
}

/*
 * Implement a code fragment for a linked
 * list that exchanges the positions of the 
 * nodes after the nodes referenced by two
 * given links t and u;
 */
void exchangeNext(const Link t, const Link u)
{
    auto temp = t->next;
    // remove node after t
    t->next = t->next->next;
    // insert removed node to position after u->next
    temp->next = u->next->next;
    u->next->next = temp;
    // remove node after u
    temp = u->next;
    u->next = u->next->next;
    // insert removed node to position after t
    temp->next = t->next;
    t->next = temp;
}

/*
 * Exercise 3.37.
 * Write a function that takes a link to
 * a list as argument and returns a link
 * to a copy of the list (a new list that 
 * conatins the same items, in the same
 * order).
 */
Link listCopy(const Link list)
{
    auto list_cp = new Node(0, nullptr);

    for (auto it_orig = list->next, it_cp = list_cp; it_orig != nullptr; it_orig = it_orig->next)
        it_cp = (it_cp->next = new Node(it_orig->item, nullptr));

    return list_cp;
}

/*
 * Exercise 3.38.
 * Write a function that takes two arguments
 * — a link to a list and a function that takes
 * a link as argument — and removes all items on
 * the given list for which the function returns
 * a nonzero value.
 */
void clearByValues(const Link list, int(*nextValueFn)(const Link list))
{
    while (list->next) {
        int value = nextValueFn(list);
        for (auto iterator = list; iterator->next; iterator = iterator->next) {
            if (iterator->next->item == value) {
                iterator->next = iterator->next->next;
                break;
            }
        }
    }
}

int nextValue(const Link list)
{
    return list->next->item;
}

/*
 * Exercise 3.39.
 * Solve Exercise 3.38, but make copies of the nodes
 * that pass the test and return a link to a list
 * containing those nodes, in the order that they
 * appear in the original list.
 */
Link listCopy(const Link list, int(*nextValueFn)(const Link list))
{
    auto list_cp = new Node(0, nullptr);
    auto iter_cp = list_cp;

    while (list->next) {
        int value = nextValueFn(list);
        for (auto iterator = list; iterator->next; iterator = iterator->next) {
            if (iterator->next->item == value) {
                // make copy
                iter_cp = (iter_cp->next = new Node(value, nullptr));
                // remove
                iterator->next = iterator->next->next;
                break;
            }
        }
    }
    return list_cp;
}

/*
 * Exercise 3.40.
 * Implement a version of Program 3.10 thas uses a head node.
 */
Link reverse(Link list)
{
    if (!list)
        return nullptr;
    Link t, y = list, tail = list->next, r = nullptr;
    while (y) {
        t = y->next;
        y->next = r;
        r = y;
        y = t;
    }
    list->next = r;
    tail->next = nullptr;
    return list;
}

/*
 * Exercise 3.41.
 * Implement a version of Program 3.11 that does not used head node;
 */
Link sort(Link list)
{
    Link result = list->next;
    Link tail = result;
    bool lastNode = false;

    while (!lastNode) {
        // indicates that, this iteartion is last in the while loop
        if (list->next == list)
            lastNode = true;
        // cut node entirely
        Link t = list->next;
        list->next = list->next->next;
        t->next = t;
        // paste node to new (sorted) list
        Link x;
        for (x = result; x->next != result; x = x->next) {
            if (x->next->item > t->item) {
                break;
            }
        }
        // if new node less than root node, insert it
        // before root node and make it as new root node
        if (t->item < result->item) {
            tail->next = t;
            t->next = result;
            result = t;
            continue;
        }
        // change tail pointer
        if (x->next == result)
            tail = t;
        // direct paste
        t->next = x->next;
        x->next = t;
    }
    return result;
}

/*
 * Exercise 3.42.
 * Implement a version of Program 3.9 that uses a head node.
 */
Link josephushElection(Link list)
{
    const int m = 5;
    Link t = list;
    while (list->next->next) {
        for (int i = 1; i < m; ++i) {
            if (!t->next) {
                if (i < m || i == 1)
                    t = list->next;
                else if (i == m - 1)
                    t = list;
            } else {
                t = t->next;
                if (!t->next)
                    t = list;
            }
        }
        t->next = t->next->next;
    }
    return list;
}

