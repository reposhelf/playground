#include <stdio.h>

int main()
{
    int drinks[] = { 4, 2, 3 };

    printf("1st drink: %i\n", drinks[0]);
    printf("1st drink: %i\n", *drinks);

    printf("3d drink: %i\n", drinks[2]);
    printf("3d drink: %i\n", *(drinks + 2));

    return 0;
}
