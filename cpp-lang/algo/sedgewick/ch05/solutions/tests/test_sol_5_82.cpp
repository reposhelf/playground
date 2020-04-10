#include "CppUTest/TestHarness.h"
#include "chapter05.h"

TEST_GROUP(test_sol_5_82)
{
};

TEST(test_sol_5_82, test_01)
{
    TraverseOrder origOrder({1, 2, 3, 4, 5, 6, 7, 8});

    Vertex nodeA = new TreeNode(1, nullptr, nullptr);
    Vertex nodeB = new TreeNode(2, nullptr, nullptr);
    Vertex nodeC = new TreeNode(3, nullptr, nullptr);
    Vertex nodeD = new TreeNode(4, nullptr, nullptr);
    Vertex nodeE = new TreeNode(5, nullptr, nullptr);
    Vertex nodeF = new TreeNode(6, nullptr, nullptr);
    Vertex nodeG = new TreeNode(7, nullptr, nullptr);
    Vertex nodeH = new TreeNode(8, nullptr, nullptr);

    nodeE->left = nodeD;
    nodeE->right = nodeH;
    nodeB->left = nodeA;
    nodeB->right = nodeC;
    nodeD->left = nodeB;
    nodeH->left = nodeF;
    nodeF->right = nodeG;

    TraverseOrder testOrder = inorderTraverseNonRec(nodeE);

    delete nodeA;
    delete nodeB;
    delete nodeC;
    delete nodeD;
    delete nodeE;
    delete nodeF;
    delete nodeG;
    delete nodeH;

    CHECK(origOrder == testOrder);
}

TEST(test_sol_5_82, test_02)
{
    TraverseOrder origOrder({4, 2, 5, 1, 3});

    Vertex root = new TreeNode(1, nullptr, nullptr);
    root->left = new TreeNode(2, nullptr, nullptr);
    root->right = new TreeNode(3, nullptr, nullptr);
    root->left->left = new TreeNode(4, nullptr, nullptr);
    root->left->right = new TreeNode(5, nullptr, nullptr);

    TraverseOrder testOrder = inorderTraverseNonRec(root);

    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    CHECK(origOrder == testOrder);
}
