#include "dear_johns.h"

#include <stdio.h>

enum response_type { DUMP, SECOND_CHANCE, MARRIAGE };

typedef struct {
    char *name;
    enum response_type type;
} response;

void dump(response r)
{
    printf("Dear %s, \n", r.name);
    puts("dump...");
}

void second_chance(response r)
{
    printf("Dear %s, \n", r.name);
    puts("second chance...");
}

void marriage(response r)
{
    printf("Dear %s, \n", r.name);
    puts("marriage...");
}

void dear_johns_test_drive()
{
    void(*replies[])(response) = { dump, second_chance, marriage };

    response r[] = {
        {"Mike", DUMP},
        {"Louis", SECOND_CHANCE},
        {"Mathew", SECOND_CHANCE},
        {"William", MARRIAGE}
    };

    const size_t SIZE = sizeof(r) / sizeof(response);
    size_t i;
    for (i = 0; i != SIZE; ++i)
        replies[r[i].type](r[i]);
}