#include "find.h"

#include <string.h>
#include <stdio.h>

const int NUM_ADS = 7;

char *ADS[] = {
    "William: single men, African American, with a good sense of humor, likes sport, TV, eat",
    "Mathew: single men, European, nonsmoking, likes art, cinema, theatre",
    "Louis: single men, Hispanic, teetotal, likes books, theatre and art",
    "Mike: divorced, European, likes trucks, sport and Justin Bieber",
    "Peter: single men, Asian, likes to play chess, gym and art",
    "Josh: single men, Jew, likes sport, cinema and theatre",
    "Jed: divorced, African American, likes theatre, books and eat"
};

void find(int(*match)(char *))
{
    puts("Search results:");
    puts("------------------------------------------------------------------");
    int i;
    for (i = 0; i < NUM_ADS; ++i) {
        if (match(ADS[i]))
            printf("%s\n", ADS[i]);
    }
    puts("------------------------------------------------------------------");
}

int sport_no_bieber(char *s)
{
    return strstr(s, "sport") && !strstr(s, "Bieber");
}

int sport_or_gym(char *s)
{
    return strstr(s, "sport") || strstr(s, "gym");
}

int ns_theatre(char *s)
{
    return strstr(s, "theatre") && strstr(s, "nonsmoking");
}

int art_theatre_eat(char *s)
{
    return strstr(s, "art") || strstr(s, "theatre") || strstr(s, "eat");
}
