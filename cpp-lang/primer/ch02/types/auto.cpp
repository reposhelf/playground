int main()
{
    auto ai = 0, *p = &ai; // ok: i is 'int' and p is 'int*'
    // auto sz = 0, pi = 3.14; // error: sz is 'int' and pi is 'double'

    int i = 0, &r = i;
    auto a = r; // a is 'int'

    const int ci = i, &cr = ci;
    auto b = ci;             // b is 'int'         (top-level const of 'ci' is ignored)
    auto c = cr;             // c is 'int'         (cr is alias of ci with top-level const)
    auto d = &i;             // d is 'int*'        (& of some int-object is 'int*')
    auto e = &ci;            // e is 'const int*'  (&ci is pointer with low-level const)
    const auto f = ci;       // f is 'const int'
    auto &g = ci;            // g is 'const int&'
    // auto &h = 42;            // error: h is non-const reference
    const auto &h = 42;      // ok: h is 'const int&'

    auto k = i, &l = i;      // k is 'int', l is 'int&'
    auto &m = ci, *p = &ci;  // m is 'const int&, p is 'const int*'
    // auto &n = i, *p2 = &ci;  // error: inference type of i is 'int' but inference type of ci is 'const int'

    return 0;
}