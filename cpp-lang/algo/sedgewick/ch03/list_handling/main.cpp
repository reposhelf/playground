#include "node.h"

#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    if (argc == 1) {
        cout << "error: expected one argument" << endl;
        return 1;
    }
    const int LIST_SIZE = atoi(argv[1]);
    Link list = createLinkedList(LIST_SIZE);
    printLinkedList(list);

    Link reversed_list = reverse(list);
    printLinkedList(reversed_list);
    return 0;
}