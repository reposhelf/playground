#include "list.h"

#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[])
{
    const int N = atoi(argv[1]);
    const int M = atoi(argv[2]);

    construct(N);

    Node t = nullptr;
    Node x = newNode(1);

    for (int i = 2; i <= N; ++i) {
        t = newNode(i);
        insert(x, t);
        x = t;
    }

    while (x != next(x)) {
        for (int i = 1; i < M; ++i)
            x = next(x);
        deleteNode(remove(x));
    }
    std::cout << item(x) << std::endl;

    return 0;
}