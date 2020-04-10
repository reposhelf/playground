#include "island.h"

#include <stdlib.h>
#include <stdio.h>

int main()
{
    FILE *file;
    if (!(file = fopen("data", "r"))) {
        puts("error: can not open file");
        return 1;
    }

    char name[20];
    fscanf(file, "%19[^\n]\n", name);

    island *islands = create(name);
    island *iterator = islands;

    while (fscanf(file, "%19[^\n]\n", name) == 1) {
        iterator->next = create(name);
        iterator = iterator->next;
    }

    display(islands);
    release(islands);

    return 0;
}