#include "CppUTest/TestHarness.h"
#include "chapter05.h"

#include <iostream>
using namespace std;

TEST_GROUP(test_sol_5_84)
{
};

TEST(test_sol_5_84, test_01)
{
    TraverseOrder expected({5, 4, 8, 2, 6, 1, 3, 7});

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

    TraverseOrder actual = levelorderTraverseNonRec(nodeE);

    delete nodeA;
    delete nodeB;
    delete nodeC;
    delete nodeD;
    delete nodeE;
    delete nodeF;
    delete nodeG;
    delete nodeH;

    CHECK(actual == expected);
}

TEST(test_sol_5_84, test_02)
{
    TraverseOrder expected({5, 4, 8, 2, 6, 1, 3, 7});

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

    TraverseOrder actual = levelorderTraverseRec(nodeE);

    delete nodeA;
    delete nodeB;
    delete nodeC;
    delete nodeD;
    delete nodeE;
    delete nodeF;
    delete nodeG;
    delete nodeH;

    CHECK(actual == expected);
}