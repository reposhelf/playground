#include "survey.h"

#include <stdio.h>

int main()
{
    printf("size of survey struct is %i\n", sizeof(survey));
    printf("size of bad_survey struct is %i\n", sizeof(bad_survey));

    survey s = {9};
    printf("%i\n", s.first_visit); // prints 1 (9 == 1001)
    return 0;
}