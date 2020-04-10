#ifndef CHAPTER05_H
#define CHAPTER05_H

#include "traverseorder.h"

#include <iostream>
#include <string>

struct Node
{
    int item;
    Node *next;
    Node(int i, Node *n) : item(i), next(n) {}
};
typedef Node *Link;

struct TreeNode
{
    int item;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int i, TreeNode *l, TreeNode *r) : item(i), left(l), right(r) {}
};
typedef TreeNode *Vertex;

inline void destroyLinkedList(Link *linkedList)
{
    if (!*linkedList)
        return;
    if (!(*linkedList)->next) {
        delete *linkedList;
        return;
    }
    destroyLinkedList(&(*linkedList)->next);
    delete *linkedList;
}

inline void print_separator()
{
    static const std::string s(80, '#');
    std::cout << std::endl << s
              << std::endl << std::endl;
}

// Exercise 5.1:
int factorial(int value);
double log10factorial(int value);
void sol_5_1();

// Exercise 5.2:
void sol_5_2();

// Exercise 5.3:
int puzzle(int n);
void sol_5_3();

// Exercise 5.4:
int puzzle(int n, unsigned &counter);
void sol_5_4();

// Exercise 5.5:
int gcd(int m, int n);
void sol_5_5();

// Exercise 5.16:
int max(int array[], int first, int last);
void sol_5_16();

// Exercise 5.17:
int max(Link linkedList);
void sol_5_17();

// Exercise 5.59:
void removeLeafs(Vertex &node, int itemToRemove);
void clearTree(Vertex &node);

// Exercise 5.60:
int max_partition(int *a, int l, int r, int k);

// Exercise 5.82:
TraverseOrder inorderTraverseNonRec(Vertex node);

// Exercise 5.83:
TraverseOrder postorderTraverseNonRec(Vertex node);

// Exercise 5.84: (wrong solution. not understood task)
TraverseOrder levelorderTraverseNonRec(Vertex node);
TraverseOrder levelorderTraverseRec(Vertex node);

#endif 
