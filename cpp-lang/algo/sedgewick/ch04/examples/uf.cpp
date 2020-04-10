#include "uf.h"

UF::UF(int N)
    : _id(new int[N]),
      _sz(new int[N])
{
    for (int i = 0; i < N; ++i) {
        _id[i] = i;
        _sz[i] = 1;
    }

}

int UF::find(int p, int q)
{
    return (find(p) == find(q));
}

void UF::unite(int p, int q)
{
    int i = find(p);
    int j = find(q);

    if (i == j)
        return;

    if (_sz[i] < _sz[j]) {
        _id[i] = j;
        _sz[j] += _sz[i];
    } else {
        _id[j] = i;
        _sz[i] += _sz[j];
    }
}

int UF::find(int x)
{
    while (x != _id[x])
        x = _id[x];
    return x;
}
