#include <iostream>

using namespace std;

struct Item
{
    int size;
    int val;

    Item()
	: size(0), val(0) {}

    Item(int s, int v)
	: size(s), val(v) {}
};

const int N = 9;
Item items[N];

void init_items()
{
    items[0] = Item(3, 4);
    items[1] = Item(3, 4);
    items[2] = Item(3, 4);
    items[3] = Item(4, 5);
    items[4] = Item(4, 5);
    items[5] = Item(7, 10);
    items[6] = Item(7, 10);
    items[7] = Item(8, 11);
    items[8] = Item(9, 13);
}

int knap(int cap)
{
    int i, space, max, t;
    for (i = 0, max = 0; i < N; ++i) {
	if ((space = cap - items[i].size) >= 0) {
	    if ((t = knap(space) + items[i].val) > max)
		max = t;
	}
    }
    return max;
}

int main(int argc, char *argv[])
{
    init_items();
    cout << knap(atoi(argv[1])) << endl;
    return 0;
}
