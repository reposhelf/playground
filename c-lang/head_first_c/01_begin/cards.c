#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
  char card_name[3];
  int count = 0;
  while (true) {
    puts("Type a card's value: ");
    scanf("%2s", card_name);
    int val = 0;
    switch (card_name[0]) {
    case 'K':
    case 'Q':
    case 'J':
      val = 10;
      break;
    case 'A':
      val = 11;
      break;
    case 'X':
      return 0;
    default:
      val = atoi(card_name);
      if ((val < 1) || (val > 10)) {
	puts("A card's value is invalid!");
	continue;
      }
      break;
    }
    if ((val > 2) && (val < 7))
      ++count;
    else if (val == 10)
      --count;

    printf("Current result: %i\n", count);
  }
  return 0;
}
