int main()
{
    int a = 0;
    int b = 0;

    int *pa = &a;
    int *pb = &b;

    // 1
    pb = pa; // or '= &a'

    // 2
    *pb = 10;
    
    return 0;
}