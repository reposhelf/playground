#include <stdio.h>

void fortune_cookie(char msg[]) {
    printf("It says: %s\n", msg);
    printf("msg is %i bytes.\n", sizeof(msg));
    printf("int is %i bytes.\n", sizeof(int));
    printf("'Tourtles!' is %i bytes.\n", sizeof("Tourtles!"));
}

int main() {
    char quote[] = "You look fat. Here, have a cookie.";
    fortune_cookie(quote);
    return 0;
}