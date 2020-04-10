#ifndef FISH_H
#define FISH_H

struct meal {
    const char *ingredients;
    float weight;
};

struct exercise {
    const char *description;
    float duration;
};

struct preferences {
    struct meal food;
    struct exercise exercise;
};

struct fish {
    const char *name;
    const char *species;
    int teeth;
    int age;
    struct preferences care;
};

void catalog(struct fish f);
void label(struct fish f);

#endif