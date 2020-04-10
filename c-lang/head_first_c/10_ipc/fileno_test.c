#include <stdio.h>

int main() {

    FILE *my_file = fopen("spanish_guitar.mp3", "r");

    int descriptor = fileno(my_file);

    printf("%i\n", descriptor);

    return 0;
}
