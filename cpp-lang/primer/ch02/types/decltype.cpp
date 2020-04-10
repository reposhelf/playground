int main()
{
    const int ci = 0, &cr = ci;
    decltype(ci) a = 0; // a is 'const int'
    decltype(cr) b = a; // b is 'const int&'

    int i = 0, *p = &i;
    decltype(i) c;      // c is 'int'
    decltype(*p) d = c; // d is 'int&'

    decltype((i)) e = c; // e is 'int&'
    return 0;
}