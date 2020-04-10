/*
 * Exercise 6.7. Write a client program that checks whether the sort routine being used is stable.
 */

#include <string>
#include <iostream>
#include <iomanip>

struct Item {
    std::string name;
    int value;
};

inline bool operator<(const Item &lhs, const Item &rhs) {
    return lhs.name < rhs.name;
}

bool stableSortBySecondKey(const Item &lhs, const Item &rhs) {
    return rhs.value < lhs.value || (lhs.value == rhs.value ? rhs < lhs : false);
}

bool unstableSortBySecondKey(const Item &lhs, const Item &rhs) {
    return rhs.value < lhs.value;
}

template<typename T> void exch(T &A, T &B) {
    T t = A;
    A = B;
    B = t;
}

template<typename T> void compexch(T &A, T &B, bool(*BinaryPredicat)(const T&, const T&)) {
    if (BinaryPredicat(A, B))
        exch(A, B);
}

template<typename T> void sort(T a[], int l, int r, bool(*BinaryPredicat)(const T&, const T&)) {
    for (int i = l + 1; i <= r; ++i)
    {
        for (int j = i; j > l; --j)
            compexch(a[j - 1], a[j], BinaryPredicat);
    }
}

int main() {
    const int N = 10;

    Item *a = new Item[N];
    a[0] = {"Adams", 1};
    a[1] = {"Wilson", 3};
    a[2] = {"Black", 2};
    a[3] = {"White", 3};
    a[4] = {"Brown", 4};
    a[5] = {"Washington", 2};
    a[6] = {"Jackson", 2};
    a[7] = {"Thompson", 4};
    a[8] = {"Jones", 4};
    a[9] = {"Smith", 1};

    sort(a, 0, N - 1, stableSortBySecondKey);

    for (int i = 0; i < N; ++i)
    std::cout << a[i].value << std::setw(14) << a[i].name << std::endl;

    delete[] a;

    return 0;
}
