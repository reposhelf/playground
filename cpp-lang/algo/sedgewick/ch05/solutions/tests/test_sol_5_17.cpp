#include "CppUTest/TestHarness.h"
#include "chapter05.h"

TEST_GROUP(tes_sol_5_17)
{
};

TEST(tes_sol_5_17, test_01)
{
    Link head = new Node(33, nullptr);
    Link tail = head;
    tail = (tail->next = new Node(45, nullptr));
    tail = (tail->next = new Node(17, nullptr));
    tail = (tail->next = new Node(49, nullptr));
    tail = (tail->next = new Node(11, nullptr));
    tail = (tail->next = new Node(35, nullptr));

    LONGS_EQUAL(49, max(head));
    destroyLinkedList(&head);
}

TEST(tes_sol_5_17, test_02)
{
    Link head = new Node(53, nullptr);
    Link tail = head;
    tail = (tail->next = new Node(45, nullptr));
    tail = (tail->next = new Node(17, nullptr));
    tail = (tail->next = new Node(49, nullptr));
    tail = (tail->next = new Node(11, nullptr));
    tail = (tail->next = new Node(35, nullptr));

    LONGS_EQUAL(53, max(head));
    destroyLinkedList(&head);
}

TEST(tes_sol_5_17, test_03)
{
    Link head = new Node(33, nullptr);
    Link tail = head;
    tail = (tail->next = new Node(45, nullptr));
    tail = (tail->next = new Node(17, nullptr));
    tail = (tail->next = new Node(49, nullptr));
    tail = (tail->next = new Node(11, nullptr));
    tail = (tail->next = new Node(53, nullptr));

    LONGS_EQUAL(53, max(head));
    destroyLinkedList(&head);
}

TEST(tes_sol_5_17, test_04)
{
    Link head = new Node(53, nullptr);
    Link tail = head;
    tail = (tail->next = new Node(45, nullptr));
    tail = (tail->next = new Node(17, nullptr));
    tail = (tail->next = new Node(49, nullptr));
    tail = (tail->next = new Node(11, nullptr));
    tail = (tail->next = new Node(53, nullptr));

    LONGS_EQUAL(53, max(head));
    destroyLinkedList(&head);
}

TEST(tes_sol_5_17, test_05)
{
    Link head = new Node(1, nullptr);

    LONGS_EQUAL(1, max(head));
    destroyLinkedList(&head);
}

TEST(tes_sol_5_17, test_06)
{
    Link head = nullptr;

    LONGS_EQUAL(0, max(head));
    destroyLinkedList(&head);
}
