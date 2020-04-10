#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T> void exch(T &A, T &B) {
    T t = A;
    A = B;
    B = t;
}

template<typename T> void compexch(T &A, T &B) {
    if (B < A)
        exch(A, B);
}

template<typename T> void sort(T a[], int l, int r) {
    for (int i = l + 1; i <= r; ++i) {
        for (int j = i; j > l; --j)
            compexch(a[j - 1], a[j]);
    }
}

int main(int argc, char **argv) {
    int N = atoi(argv[1]);
    int sw = atoi(argv[2]);
    int *a = new int[N];

    if (sw) {
        for (int i = 0; i < N; ++i)
            a[i] = 1000 * (1.0 * rand() / RAND_MAX);
    } else {
        N = 0;
        while (cin >> a[N])
            ++N;
    }

    sort(a, 0, N - 1);

    for (int i = 0; i < N; ++i)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
