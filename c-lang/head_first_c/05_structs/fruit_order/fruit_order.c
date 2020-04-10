#include "fruit_order.h"

#include <stdio.h>

void display(fruit_order order)
{
    printf("This order contains ");

    if (order.units == COUNT)
        printf("%i %s\n", order.amount.count, order.name);
    else if (order.units == POUNDS)
        printf("%2.2f pounds of %s\n", order.amount.weight, order.name);
    else
        printf("%2.2f pints of %s\n", order.amount.volume, order.name);
}