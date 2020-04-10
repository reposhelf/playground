/*
 * 4.11.
 * Given two sequences, give an algorithm for determining whether or not asterisks
 * can be added to make the first produce the second, when interpreted as a sequence
 * of stack operations.
 */
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

bool canProduce(const char *first, const char *second)
{
    const size_t scount = strlen(second);
    if (0 < int(scount - strlen(first)))
        return false;

    for (int i = 0, j = scount - 1; j >= 0; ++i, --j) {
        if (first[i] != second[j])
            return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        cout << "need two sequences" << endl;
        return 1;
    }

    if (canProduce(argv[1], argv[2]))
        cout << "The first sequence can to produce the second sequence" << endl;
    else
        cout << "The first sequence can't to produce the second sequence" << endl;

    return 0;
}
