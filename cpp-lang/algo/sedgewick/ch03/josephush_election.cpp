#include <iostream>
#include <cstdlib>

struct Node
{
    int item;
    Node *next;

    Node(int x, Node *t)
    {
        item = x;
        next = t;
    }
};
typedef Node *Link;

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    Link node = new Node(1, nullptr);
    node->next = node;
    for (int i = 2; i <= n; ++i)
        node = (node->next = new Node(i, node->next));

    while (node != node->next) {
        for (int i = 1; i < m; ++i)
            node = node->next;
        std::cout << node->item << " ";
        node->next = node->next->next;
    }
    std::cout << std::endl << node->item << std::endl;
    return 0;
}