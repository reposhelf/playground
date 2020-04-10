#include "chapter05.h"

#include <stack>
#include <set>

// #define USE_TWO_STACKS

using namespace std;

inline void visit(Vertex node, TraverseOrder &order)
{
    order.push_back(node->item);
}

#ifdef USE_TWO_STACKS
TraverseOrder postorderTraverseNonRec(Vertex node)
{
    /*
     * 1. Push root to first stack.
     * 2. Loop while first stack is not empty
     *    2.1 Pop a node from first stack and push it to second stack
     *    2.2 Push left and right children of the popped node to first stack
     * 3. Print contents of second stack
     */

    stack<Vertex> s1;
    stack<Vertex> s2;
    TraverseOrder order;

    s1.push(node);
    while (!s1.empty()) {
        s2.push(node = s1.top());
        s1.pop();

        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }

    while (!s2.empty()) {
        visit(s2.top(), order);
        s2.pop();
    }
    return order;
}

#else
TraverseOrder postorderTraverseNonRec(Vertex root)
{
    /*
     * 1.1 Create an empty stack
     * 2.1 Do following while root is not NULL
     *     a) Push root's right child and then root to stack.
     *     b) Set root as root's left child.
     * 2.2 Pop an item from stack and set it as root.
     *     a) If the popped item has a right child and the right child 
     *        is at top of stack, then remove the right child from stack,
     *        push the root back and set root as root's right child.
     *     b) Else print root's data and set root as NULL.
     * 2.3 Repeat steps 2.1 and 2.2 while stack is not empty.
     */

    stack<Vertex> s;
    TraverseOrder order;

    do {
        while (root) {
            if (root->right)
                s.push(root->right);
            s.push(root);
            root = root->left;
        }

        root = s.top();
        s.pop();
        if (root->right && !s.empty() && root->right == s.top()) {
            s.pop();
            s.push(root);
            root = root->right;
        } else {
            visit(root, order);
            root = nullptr;
        }
    } while (!s.empty());

    return order;
}

#endif