#include "stdio.h"

/*
 * Exercise 1.6. Verify that the expression getchar() != EOF is 0 or 1.
 */
int main()
{
    int c;

    do {
        c = getchar() != EOF;
        printf("The result is %d\n", c);
    } while (c);

    return 0;
 }
