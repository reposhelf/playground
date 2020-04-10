#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#include <cstdlib>

namespace AdjacencyList {

struct node {
    int item;
    node *next;

    node(int i, node *n) {
        item = i;
        next = n;
    }
};
typedef node *link;

link *makeList(size_t size);
void displayList(link *list, size_t size);
void releaseList(link *list, size_t size);

void adjacencyListTestDrive();

};

#endif