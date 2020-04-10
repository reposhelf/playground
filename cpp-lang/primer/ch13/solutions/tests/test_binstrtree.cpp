#include "CppUTest/TestHarness.h"
#include "binstrtree.h"
#include "treenode.h"

#include <vector>
using namespace std;

TreeNode *create_tree()
{
    TreeNode *nodeA = new TreeNode("A", 0, nullptr, nullptr);
    TreeNode *nodeC = new TreeNode("C", 0, nullptr, nullptr);
    TreeNode *nodeB = new TreeNode("B", 0, nodeA, nodeC);
    TreeNode *nodeD = new TreeNode("D", 0, nodeB, nullptr);
    TreeNode *nodeG = new TreeNode("G", 0, nullptr, nullptr);
    TreeNode *nodeF = new TreeNode("F", 0, nullptr, nodeG);
    TreeNode *nodeH = new TreeNode("H", 0, nodeF, nullptr);
    TreeNode *nodeE = new TreeNode("E", 0, nodeD, nodeH);
    return nodeE;
}

void destroy_tree(TreeNode* &root)
{
    delete root;
    root = nullptr;
}

void traverse(TreeNode *root, vector<string> &vec)
{
    if (!root)
        return;
    vec.push_back(root->value());
    traverse(root->left(), vec);
    traverse(root->right(), vec);
}

void traverse(BinStrTree *bst, vector<string> &vec)
{
    if (!bst)
        return;
    traverse(bst->root(), vec);
}

TEST_GROUP(test_binstrtree)
{
};

TEST(test_binstrtree, test_1)
{
    BinStrTree bst(create_tree());
    BinStrTree copy_bst = bst;

    vector<string> expected({"E", "D", "B", "A", "C", "H", "F", "G"});
    vector<string> actual;
    vector<string> copy_actual;

    traverse(&bst, actual);
    traverse(&copy_bst, copy_actual);

    CHECK(actual == expected);
    CHECK(copy_actual == expected);
}

TEST(test_binstrtree, test_2)
{
    TreeNode *root = create_tree();
    TreeNode *copy_left = new TreeNode(*root->left());

    vector<string> expected({"D", "B", "A", "C"});
    vector<string> actual;

    traverse(copy_left, actual);

    CHECK(actual == expected);

    destroy_tree(root);
    destroy_tree(copy_left);
}