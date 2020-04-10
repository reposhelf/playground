/*
 * Exercise 5.15:
 * Write a recursive program for reversing the order of the nodes in a linked list.
 * Hint: Use a global variable.
 */

#include <iostream>

struct Node
{
    int item;
    Node *next;

    Node(int i, Node *n)
        : item(i), next(n) {}
};
typedef Node *Link;

void error(const char *msg)
{
    std::cerr << msg << std::endl;
    exit(1);
}

Link create_linked_list(size_t size, int start_value)
{
    Link head = new Node(start_value, nullptr);
    Link tail = head;

    for (size_t i = 0; i < size - 1; ++i) {
        tail->next = new Node(++start_value, nullptr);
        tail = tail->next;
    }

    return head;
}

void destroy_linked_list(Link *list)
{
    if (!(*list))
        return;

    if ((*list)->next)
        destroy_linked_list(&(*list)->next);

    delete *list;
    *list = nullptr;
}

void reverse_linked_list_r(Link original, Link *reversed)
{
    if (original) {
        *reversed = new Node(original->item, *reversed);
        reverse_linked_list_r(original->next, reversed);
    }
}

void reverse_linked_list(Link *list)
{
    Link reversed = nullptr;
    reverse_linked_list_r(*list, &reversed);
    destroy_linked_list(list);
    *list = reversed;
}

void print_linked_list(Link list)
{
    while (list) {
        std::cout << list->item << " ";
        list = list->next;
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    if (argc < 3)
        error("Type: PROGRAM_NAME <SIZE> <START_VALUE>");

    const int size = std::atoi(argv[1]);
    const int start_value = std::atoi(argv[2]);

    Link list = create_linked_list(size, start_value);
    print_linked_list(list);

    reverse_linked_list(&list);
    print_linked_list(list);

    destroy_linked_list(&list);

    return 0;
}