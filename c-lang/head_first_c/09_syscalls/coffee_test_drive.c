#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    char *my_env[] = {"FOOD=coffee", NULL};
    if (execle("coffee", "coffee", "donuts", NULL, my_env) == -1) {
	fprintf(stderr, "Can not create an order: %s\n", strerror(errno));
	return 1;
    }
    return 0;
}
