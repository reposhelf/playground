#include "chapter05.h"

#include <queue>

using namespace std;

inline void visit(Vertex node, TraverseOrder &order)
{
    order.push_back(node->item);
}

TraverseOrder levelorderTraverseNonRec(Vertex node)
{
    queue<Vertex> q;
    q.push(node);
    TraverseOrder order;
    while (!q.empty()) {
        visit(node = q.front(), order);
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    return order;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void visitLevel(Vertex node, int level, TraverseOrder &order)
{
    if (!node)
        return;
    if (level == 1) {
        visit(node, order);
    } else if (level > 1) {
        visitLevel(node->left, level - 1, order);
        visitLevel(node->right, level - 1, order);
    }
}

int height(Vertex node)
{
    if (!node)
        return 0;
    int lh = height(node->left);
    int rh = height(node->right);
    return lh > rh ? lh + 1 : rh + 1;
}

TraverseOrder levelorderTraverseRec(Vertex node)
{
    TraverseOrder order;
    int h = height(node);
    for (int i = 1; i <= h; ++i)
        visitLevel(node, i, order);
    return order;
}