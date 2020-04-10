#include "adjacency_list.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

namespace AdjacencyList {

link *makeList(size_t size)
{
    link *adj = new link[size];
    for (size_t i = 0; i < size; ++i)
        adj[i] = nullptr;

    int i, j;
    while (cin >> i >> j) {
        adj[i] = new node(j, adj[i]);
        adj[j] = new node(i, adj[j]);
    }

    return adj;
}

void displayList(link *list, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        cout << i << " --> ";
        link n = list[i];
        while (n) {
            cout << n->item << " ";
            n = n->next;
        }
        cout << endl;
    }
}

void releaseList(link *list, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        link killer = list[i];
        while (killer) {
            link t = killer->next;
            delete killer;
            killer = t;
        }
    }
    delete[] list;
}

void adjacencyListTestDrive()
{
    static const size_t SIZE = 8;
    link * adj = makeList(SIZE);
    displayList(adj, SIZE);
    releaseList(adj, SIZE);
}

};