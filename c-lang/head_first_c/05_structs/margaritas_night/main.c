#include "margarita.h"

#include <stdio.h>

int main()
{
    margarita m1 = {2.0, 1.0, {2.0}};
    printf("%2.1f portions of tequila\n%2.1f portions of cointreau\n%2.1f portions of lemon\n\n",
            m1.tequila, m1.cointreau, m1.citrus.lemon);

    margarita m2 = {2.0, 1.0, {0.5}};
    printf("%2.1f portions of tequila\n%2.1f portions of cointreau\n%2.1f portions of lemon\n\n",
            m2.tequila, m2.cointreau, m2.citrus.lemon);

    margarita m3 = {2.0, 1.0, {.lime_pieces = 1}};
    printf("%2.1f portions of tequila\n%2.1f portions of cointreau\n%i piece of lime\n\n",
            m3.tequila, m3.cointreau, m3.citrus.lime_pieces);

    return 0;
}