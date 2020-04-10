#include <stdio.h>

/*
 * Exercise 1.4. Write a program to print the corresponding Celsius to
 * Fahrenheit table.
 */

int main()
{
    float celsius, fahr;
    int lower, upper, step;

    lower = -40;
    upper = 300;
    step = 20;

    celsius = lower;
    printf("%3c %6c\n", 'C', 'F');
    while (celsius <= upper) {
	fahr = 32 + (9.0 / 5.0) * celsius;
	printf("%3.0f %6.1f\n", celsius, fahr);
	celsius += step;
    }
    
    return 0;
}
