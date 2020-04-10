#include "adjacency_mtrx.h"

#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

void makeMatrix()
{
    static const size_t V = 8;
    int adj_mtrx[V][V];
    for (size_t i = 0; i < V; ++i) {
        for (size_t j = 0; j < V; ++j) {
            adj_mtrx[i][j] = 0;
        }
    }
    for (size_t i = 0; i < V; ++i)
        adj_mtrx[i][i] = 1;
    int i, j;
    while (cin >> i >> j) {
        adj_mtrx[i][j] = 1;
        adj_mtrx[j][i] = 1;
    }
    for (size_t r = 0; r < V; ++r) {
        for (size_t c = 0; c < V; ++c) {
            cout << adj_mtrx[r][c] << " ";
        }
        cout << endl;
    }
}