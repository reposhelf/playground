#include "chapter05.h"

void removeLeafs(Vertex &node, int itemToRemove)
{
    if (!node)
        return;

    if (!(node->left || node->right)) {
        if (node->item == itemToRemove) {
            delete node;
            node = nullptr;
        }
        return;
    }

    if (node->left)
        removeLeafs(node->left, itemToRemove);

    if (node->right)
        removeLeafs(node->right, itemToRemove);
}

void clearTree(Vertex &node)
{
    if (!node)
        return;
    clearTree(node->left);
    clearTree(node->right);
    delete node;
    node = nullptr;
}
