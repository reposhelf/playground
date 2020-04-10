#include "fish.h"

#include <stdio.h>

void catalog(struct fish f)
{
    printf("%s is %s with %i teeths. It is %i years old.\n",
           f.name, f.species, f.teeth, f.age);
}

void label(struct fish f)
{
    printf("Nickname: %s\nSpecies: %s\n%i years old, %i teeths\n"
           "Give %2.2f kg of %s and allow to %s for about %2.2f hours\n.",
           f.name, f.species, f.age, f.teeth, f.care.food.ingredients,
           f.care.food.weight, f.care.exercise.description,
           f.care.exercise.duration);
}