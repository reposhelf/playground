#ifndef PRICE_DRINKS_H
#define PRICE_DRINKS_H

enum drink 
{
  MUDSLIDE,
  FUZZY_NAVEL,
  MONKEY_GLAND,
  ZOMBIE
};

double price(enum drink d);
double total_price(int argc, ...);

#endif /* price_drinks.h */
