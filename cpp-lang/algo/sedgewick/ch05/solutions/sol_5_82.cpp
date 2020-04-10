#include "chapter05.h"

#include <stack>
#include <set>

using namespace std;

inline void visit(Vertex node, TraverseOrder &order)
{
    order.push_back(node->item);
}

TraverseOrder inorderTraverseNonRec(Vertex node)
{
    /*
     * Algorithm:
     * 1) Create an empty stack S.
     * 2) Initialize current node as root
     * 3) Push the current node to S and set current = current->left until current is NULL
     * 4) If current is NULL and stack is not empty then
     *      a) Pop the top item from stack.
     *      b) Print the popped item, set current = popped_item->right
     *      c) Go to step 3.
     * 5) If current is NULL and stack is empty then we are done.
     */
    if (!node)
        return TraverseOrder();

    stack<Vertex> s;
    Vertex curr = node;
    TraverseOrder order;

    do {
        s.push(curr);
        curr = curr->left;
        while (!curr && !s.empty()) {
            visit(curr = s.top(), order);
            curr = curr->right;
            s.pop();
        }
    } while (curr || !s.empty());

    return order;
}