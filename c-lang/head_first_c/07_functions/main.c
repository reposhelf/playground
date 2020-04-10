#include "find.h"
#include "libc_sort.h"
#include "dear_johns.h"
#include "print_ints.h"
#include "price_drinks.h"

#include <stdio.h>

int main()
{
  printf("Price: %.2f\n", total_price(2, MONKEY_GLAND, MUDSLIDE));
  printf("Price: %.2f\n", total_price(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));
  printf("Price: %.2f\n", total_price(1, ZOMBIE));
  return 0;
}
