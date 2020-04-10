#include "print_ints.h"

#include <stdarg.h>
#include <stdio.h>

void print_ints(int argc, ...)
{
  va_list ap;
  va_start(ap, argc);

  size_t i;
  for (i = 0; i != argc; ++i)
    printf("number: %i\n", va_arg(ap, int));

  va_end(ap);
}
