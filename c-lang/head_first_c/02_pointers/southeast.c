#include <stdio.h>

void go_south_east(int *lat, int *lon) {
    --(*lat);
    ++(*lon);
}

int main() {
    int latitude = 32;
    int longitude = -64;
    go_south_east(&latitude, &longitude);
    printf("Stop! Our coordinates are: [%i, %i]\n", latitude, longitude);
    return 0;
}