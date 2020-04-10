#include <stdio.h>

/*
 * print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300
 */

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;    // the lower limit of temperature
    upper = 300;  // the upper limit of temperature
    step = 20;    // the step value

    fahr = lower;
    printf("%3c %6c\n", 'F', 'C');
    while (fahr <= upper) {
	celsius = (5.0 / 9.0) * (fahr - 32);
	printf("%3.0f %6.1f\n", fahr, celsius);
	fahr += step;
    }
    
    return 0;
}
