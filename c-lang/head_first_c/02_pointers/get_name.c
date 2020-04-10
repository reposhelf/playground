#include <stdio.h>

int main()
{
    char first_name[20];
    char last_name[20];

    printf("Enter a first name and last name: ");
    scanf("%19s %19s", first_name, last_name);
    printf("First name: %s\nLast name: %s\n", first_name, last_name);

    // crash is possible here
    // char food[5];
    // printf("Enter your favorite food: ");
    // scanf("%s", food);
    // printf("Your favorite food: %s\n", food);

    char food[5];
    printf("Enter your favorite food: ");
    fgets(food, sizeof(food), stdin);
    printf("Your favorite food is %s\n", food);

    return 0;
}