#include "CppUTest/TestHarness.h"
#include "chapter05.h"

#include <vector>
#include <iostream>

using namespace std;

void traverse(Vertex node, vector<int> &items)
{
    if (!node)
        return;
    items.push_back(node->item);
    traverse(node->left, items);
    traverse(node->right, items);
}

TEST_GROUP(tes_sol_5_59)
{
};
 
TEST(tes_sol_5_59, test_01)
{
    Vertex root = new TreeNode(0, nullptr, nullptr);
    // make 1st level
    root->right = new TreeNode(1, nullptr, nullptr);
    root->left = new TreeNode(2, nullptr, nullptr);
    //make 2nd level
    root->right->right = new TreeNode(42, nullptr, nullptr);
    root->left->left = new TreeNode(3, nullptr, nullptr);
    root->left->right = new TreeNode(4, nullptr, nullptr);
    // make 3rd level
    root->left->left->left = new TreeNode(42, nullptr, nullptr);
    root->left->left->right = new TreeNode(42, nullptr, nullptr);
    root->left->right->left = new TreeNode(5, nullptr, nullptr);
    root->left->right->right = new TreeNode(42, nullptr, nullptr);

    vector<int> expected = {0, 2, 3, 4, 5, 1};
    vector<int> actual;
    removeLeafs(root, 42);
    traverse(root, actual);

    CHECK(expected == actual);

    clearTree(root);
}
