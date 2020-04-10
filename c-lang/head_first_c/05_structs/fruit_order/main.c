#include "fruit_order.h"

int main()
{
    fruit_order apples = {"apples", "England", .amount.count = 144, COUNT};
    fruit_order strawberries = {"strawberries", "Spain", .amount.weight = 17.60, POUNDS};
    fruit_order oj = {"orange juice", "USA", .amount.volume = 10.50, PINTS};

    display(apples);
    display(strawberries);
    display(oj);
    
    return 0;
}