#include "array2d_lists.h"
#include "point.h"

#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

struct node {
    Point point;
    node *next;

    node(Point p, node *n) {
        point = p;
        next = n;
    }
    node() {
        next = nullptr;
        point.x = 0.0;
        point.y = 0.0;
    }
};
typedef node *link;
static link **grid;
static int G;
static int cnt = 0;
static float d;

void gridInsert(float x, float y)
{
    int X = x * G + 1;
    int Y = y * G + 1;
    Point p;
    p.x = x;
    p.y = y;
    // link s = nullptr;
    link t = new node(p, grid[X][Y]);
    for (int i = X - 1; i <= X + 1; ++i) {
        for (int j = Y - 1; j <= Y + 1; ++j) {
            for (link s = grid[i][j]; s != nullptr; s = s->next) {
                if (distance(s->point, t->point) < d)
                    ++cnt;
            }
        }
    }
    grid[X][Y] = t;
}

link **malloc2d(int rows, int columns)
{
    link **a = new link*[rows];
    for (int i = 0; i < rows; ++i)
        a[i] = new link[columns];
    return a;
}

float randFloat()
{
    return 1.0 * rand() / RAND_MAX;
}

void array2dlistsTestDrive(int argc, char **argv)
{
    int N = atoi(argv[1]);
    d = atof(argv[2]);
    G = 1/d;
    grid = malloc2d(G + 2, G + 2);
    for (int i = 0; i < G + 2; ++i) {
        for (int j = 0; j < G + 2; ++j) {
            grid[i][j] = nullptr;
        }
    }
    for (int i = 0; i < N; ++i)
        gridInsert(randFloat(), randFloat());
    cout << cnt << " pairs within " << d << endl;
}