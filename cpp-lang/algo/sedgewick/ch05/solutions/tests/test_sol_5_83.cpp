#include "CppUTest/TestHarness.h"
#include "chapter05.h"

TEST_GROUP(test_sol_5_83)
{
};

TEST(test_sol_5_83, test_01)
{
    TraverseOrder origOrder({1, 3, 2, 4, 7, 6, 8, 5});

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

    TraverseOrder testOrder = postorderTraverseNonRec(nodeE);

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

TEST(test_sol_5_83, test_02)
{
    TraverseOrder origOrder({4, 5, 2, 3, 1});

    Vertex root = new TreeNode(1, nullptr, nullptr);
    root->left = new TreeNode(2, nullptr, nullptr);
    root->right = new TreeNode(3, nullptr, nullptr);
    root->left->left = new TreeNode(4, nullptr, nullptr);
    root->left->right = new TreeNode(5, nullptr, nullptr);

    TraverseOrder testOrder = postorderTraverseNonRec(root);

    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    CHECK(origOrder == testOrder);
}
