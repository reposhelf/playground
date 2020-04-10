#ifndef LIST_H
#define LIST_H

struct Node
{
    Node(int i, Node *n) 
        : item(i), next(n) {}

    int item;
    Node *next;
};
typedef Node *Link;

Link createRandomList(int length);
Link createSortedList(int length);
void display(const Link list);

/*
 * Exercise 3.33.
 * Write a function that moves the
 * largest item on a given list to
 * be the final node on the list.
 */
void moveLargestToEnd(const Link list);

/*
 * Exercise 3.34.
 * Write a function that moves the
 * smallest item on a given list to
 * be the first node on the list.
 */
void moveSmallestToBegin(const Link list);

 /*
  * Exercise 3.35.
  * Write a function that rearranges
  * a linked list to put the nodes in
  * even positions of the nodes after
  * the nodes in odd positions in the
  * list, preserving the relative order
  * of both the evens and the odds.
  */
void separateEvensAndOdds(const Link list);

/*
 * Exercise 3.36.
 * Implement a code fragment for a linked
 * list that exchanges the positions of the 
 * nodes after the nodes referenced by two
 * given links t and u;
 */
void exchangeNext(const Link t, const Link u);

/*
 * Exercise 3.37.
 * Write a function that takes a link to
 * a list as argument and returns a link
 * to a copy of the list (a new list that 
 * conatins the same items, in the same
 * order).
 */
Link listCopy(const Link list);

/*
 * Exercise 3.38.
 * Write a function that takes two arguments
 * — a link to a list and a function that takes
 * a link as argument — and removes all items on
 * the given list for which the function returns
 * a nonzero value.
 */
void clearByValues(const Link list, int(*)(const Link list));
int nextValue(const Link list);

/*
 * Exercise 3.39.
 * Solve Exercise 3.38, but make copies of the nodes
 * that pass the test and return a link to a list
 * containing those nodes, in the order that they
 * appear in the original list.
 */
Link listCopy(const Link list, int(*)(const Link list));

/*
 * Exercise 3.40.
 * Implement a version of Program 3.10 thas uses a head node.
 */
Link reverse(Link list);

/*
 * Exercise 3.41.
 * Implement a version of Program 3.11 that does not used head node;
 */
Link sort(Link list);

/*
 * Exercise 3.42.
 * Implement a version of Program 3.9 that uses a head node.
 */
 Link josephushElection(Link list);
 
#endif