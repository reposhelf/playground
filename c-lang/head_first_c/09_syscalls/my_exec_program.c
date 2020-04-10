#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main()
{
    char *my_env[] = {"JUICE=An apple", NULL};
    execle("diner_inf",
	   "diner_inf",
	   "4",
	   NULL,
	   my_env);
    puts(strerror(errno));
    return 0;
}
