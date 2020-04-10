#include "price_drinks.h"

#include <stdarg.h>
#include <stdlib.h>

double price(enum drink d)
{
  switch (d)
    {
    case MUDSLIDE:
      return 6.79;
    case FUZZY_NAVEL:
      return 5.31;
    case MONKEY_GLAND:
      return 4.82;
    case ZOMBIE:
      return 5.89;
    default:
      break;
    }
  return 0.0;
}

double total_price(int argc, ...)
{
  va_list ap;
  double total = 0.0;
  va_start(ap, argc);

  size_t i;
  for (i = 0; i != argc; ++i)
    total += price(va_arg(ap, enum drink));

  va_end(ap);

  return total;
}
