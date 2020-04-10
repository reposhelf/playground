#include "chapter4.h"
#include "point.h"
#include "stack.h"
#include "uf.h"
#include "complex.h"

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

// Program 4.2: find nearest points
int findNearestPoints(int argc, char **argv)
{
    if (argc < 3) {
        cout << "<program_name> <points_count> <range_value>" << endl;
        return 1;
    }

    static const float RANGE = atof(argv[2]);
    static const size_t SIZE = atoi(argv[1]);

    Point *points = new Point[SIZE];
    size_t count = 0;

    for (size_t i = 0; i != SIZE; ++i) {
        for (size_t j = i + 1; j != SIZE; ++j) {
            if (points[j].distance(points[i]) < RANGE)
                ++count;
        }
    }
    cout << count << " points within " << RANGE << endl;

    return 0;
}

// Program 4.5: postfix-expression evaluation
void postfixExprEval(char **argv)
{
    char *a = argv[1];
    const size_t count = strlen(a);
    ListBased::Stack<int> save(count);
    for (size_t i = 0; i < count; ++i) {
        if (a[i] == '+')
            save.push(save.pop() + save.pop());
        if(a[i] == '*')
            save.push(save.pop() * save.pop());
        if ((a[i] >= '0') && (a[i] <= '9'))
            save.push(0);
        while ((a[i] >= '0') && (a[i] <= '9'))
            save.push(10 * save.pop() + (a[i++] - '0'));
    }
    cout << save.pop() << endl;
}

// Program 4.6: infix-to-posrfix conversion
void infixToPostfix(char **argv)
{
    char *a = argv[1];
    const size_t count = strlen(a);
    ListBased::Stack<char> ops(count);
    for (size_t i = 0; i < count; ++i) {
        if (a[i] == ')')
            cout << ops.pop() << " ";
        if ((a[i] == '+') || (a[i] == '*'))
            ops.push(a[i]);
        if ((a[i] >= '0') && (a[i] <= '9'))
            cout << a[i] << " ";
    }

    while (!ops.empty())
        cout << ops.pop() << " ";

    cout << endl;
}

// Program 4.10: equivalence-relations client
void ufClient(char **argv)
{
    const int N = atoi(argv[1]);
    UF info(N);

    int p, q;
    while (cin >> p >> q) {
        if (!info.find(p, q)) {
            info.unite(p, q);
            cout << " " << p << " " << q << endl;
        }
    }
}

// Program 4.17: Complex number driver (roots of unity)
void complexNumbersDriver(char **argv)
{
    const int N = atoi(argv[1]);
    cout << N << " complex roots of unity" << endl;
    for (int i = 0; i < N; ++i) {
        double theta = 2 * 3.14159 * i / N;
        Complex t(cos(theta), sin(theta)), x = t;
        cout << i << ": " << t << " ";
        for (int j = 0; j < N - 1; ++j)
            x *= t;
        cout << x << endl;
    }
}

