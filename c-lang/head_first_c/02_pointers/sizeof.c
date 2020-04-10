#include <stdio.h>

int main()
{
    int array[] = {1, 2, 3};
    int *pArray = &array[0];

    printf("array size: %i\n", sizeof(array)); // 12 (x64)
    printf("pointer size: %i\n", sizeof(pArray)); // 8 (x64)

    return 0;
}