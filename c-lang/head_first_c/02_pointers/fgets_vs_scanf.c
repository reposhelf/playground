#include <stdio.h>

int main()
{
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