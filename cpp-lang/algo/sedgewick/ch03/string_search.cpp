#include <iostream>
using std::cin;
using std::cout;
using std::endl;

static const int N = 10000;

int main(int argc, char *argv[])
{
    int i;
    char t;
    int a[N];
    char *p = argv[1];
    for (i = 0; i < N - 1; a[i] = t, ++i) {
        if (!cin.get(t))
            break;
    }
    a[i] = 0;

    for (i = 0; a[i] != 0; ++i) {
        int j;
        for (j = 0; p[j] != 0; ++j) {
            if (a[i + j] != p[j])
                break;
        }
        if (p[j] == 0)
            cout << i << " ";
    }
    cout << endl;
    
    return 0;
}