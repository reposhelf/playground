#include "stdio.h"
#include "unistd.h"

int main(int argc, char *argv[])
{
    char *delivery = "";
    int thick = 0;
    char ch;

    while ((ch = getopt(argc, argv, "d:t")) != EOF) {
        switch (ch) {
            case 'd':
                delivery = optarg;
                break;
            case 't':
                thick = 1;
                break;
            default:
                fprintf(stderr, "Unknown parameter: %s\n", optarg);
                return 1;
        }
    }

    argc -= optind;
    argv += optind;

    if (thick)
        puts("Thick crust");

    if (delivery[0])
        printf("Will be delivered to %s.\n", delivery);

    puts("Ingredients:");

    int count;
    for (count = 0; count < argc; ++count)
        puts(argv[count]);

    return 0;
}