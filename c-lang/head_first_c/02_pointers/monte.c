#include <stdio.h>

int main()
{
    char cards[] = "JQK";
    char a_card = cards[2];                                                                       
    cards[2] = cards[1];
    cards[1] = cards[0];
    cards[0] = cards[2];
    cards[2] = cards[1];
    cards[1] = a_card;
    puts(cards);

    // use const char * instead of char *
    // in case of assignment of string literals
    // const char *s = "Some string";
    // s[0] = 'G';

    return 0;
}