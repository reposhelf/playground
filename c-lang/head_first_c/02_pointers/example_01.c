#include <stdio.h>

int y = 1;  // stored in the global area

int main() {
    int x = 4;  // stored in the "stack"
    int z = 8;  // stored in the "stack"
    printf("x is stored at the address %p\n", x);
    printf("z is stored at the address %p\n", z);
    printf("y is stored at the address %p\n", y);
    return 0;
}