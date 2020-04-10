#include <stdio.h>

void skip(const char *msg)
{
    puts(msg + 7);
}

int main()
{
    char *msg_from_amy = "Do not call me";
    skip(msg_from_amy);

    return 0;
}
