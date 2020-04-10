int main()
{
    const int i = 42;
    auto j = i;                  // j is 'int'
    const auto &k = i;           // k is 'const int&'
    auto *p = &i;                // p is 'const int*'
    const auto  j2 = i, &k2 = i; // j2 is 'const int' and k2 is 'const int&'
    return 0;
}