#include "libc_sort.h"

#include <stdlib.h>
#include <stdio.h>

enum SortOrder {Ascending, Descending};

// NUMBERS

int compare_scores(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int compare_scores_desc(const void *a, const void *b)
{
    return -compare_scores(a, b);
}

void sort_ints(enum SortOrder so)
{
    int scores[] = {543, 323, 32, 554, 11, 3, 112};
    const size_t sz = sizeof(scores) / sizeof(int);

    switch (so) {
    case Ascending:
        puts("Ascending");
        qsort(scores, sz, sizeof(int), compare_scores);
        break;
    case Descending:
        puts("Descending");
        qsort(scores, sz, sizeof(int), compare_scores_desc);
        break;
    default:
        break;
    }

    size_t i;
    for (i = 0; i != sz; ++i)
        printf("%d\n", scores[i]);
}

// RECTANGLES

typedef struct {
    int width;
    int height;
} rectangle;

int compare_areas(const void *a, const void *b)
{
    rectangle *r1 = (rectangle *)a;
    rectangle *r2 = (rectangle *)b;

    return r1->width * r1->height - r2->width * r2->height;
}

int compare_areas_desc(const void *a, const void *b)
{
    return -compare_areas(a, b);
}

void sort_rects(enum SortOrder so)
{
    rectangle rects[] = {
        {3, 5},
        {7, 2},
        {5, 6},
        {8, 7},
        {5, 9},
        {6, 4},
        {2, 2},
        {2, 7}
    };

    const size_t sz = sizeof(rects) / sizeof(rectangle);
    switch (so) {
    case Ascending:
        puts("Ascending");
        qsort(rects, sz, sizeof(rectangle), compare_areas);
        break;
    case Descending:
        puts("Descending");
        qsort(rects, sz, sizeof(rectangle), compare_areas_desc);
        break;
    default:
        break;
    }

    size_t i;
    for (i = 0; i != sz; ++i)
        printf("rectangle: (%i, %i: square=%i)\n",
            rects[i].width, rects[i].height, rects[i].width * rects[i].height);
}

// NAMES

int compare_names(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}

int compare_names_desc(const void *a, const void *b)
{
    return -compare_names(a, b);
}

void sort_names(enum SortOrder so)
{
    char *names[] = {
        "Michael Sheen",
        "Christian Bale",
        "Fernando Alonso",
        "Xabi Alonso",
        "Charlie Sheen",
        "Michael Dudikoff",
        "Brent Burns",
        "Valeriy Harlamov"
    };

    const size_t sz = sizeof(names) / sizeof(char *);
    switch (so) {
    case Ascending:
        puts("Ascending");
        qsort(names, sz, sizeof(char *), compare_names);
        break;
    case Descending:
        puts("Descending");
        qsort(names, sz, sizeof(char *), compare_names_desc);
        break;
    default:
        break;
    }

    size_t i;
    for (i = 0; i != sz; ++i)
        printf("%s\n", names[i]);
}

void libc_sort_test_drive()
{
    puts("Sorted numbers:");
    sort_ints(Ascending);
    sort_ints(Descending);
    sort_rects(Ascending);
    sort_rects(Descending);
    sort_names(Ascending);
    sort_names(Descending);
}