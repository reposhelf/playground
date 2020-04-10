#include "chapter05.h"

int max_partition(int *a, int l, int r, int k)
{
    // single element
    if (l == r)
        return a[l];
    // fint max for not partitionable set
    const int elementsCount = r - l + 1;
    if (elementsCount < k) {
        int m = (l + r) / 2;
        int u = max_partition(a, l, m, k);
        int v = max_partition(a, m + 1, r, k);
        return (u < v ? v : u);
    }
    // partitionable
    int parts[k];
    for (int i = 0; i < k; ++i)
        parts[i] = 0;
    // each part contains count of elements
    for (int i = 0, j = 0; i < elementsCount; ++i, j = (j + 1) % k)
        parts[j] += 1;
    // find max for partitionable set
    int max = 0;
    for (int i = 0; i < k; ++i) {
        int old_l = l;
        l += parts[i];
        int m = max_partition(a, old_l, l - 1, k);
        max = (m < max ? max : m);
    }
    return max;
}
