#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char *argv[])
{
    int engine_count;
    char ch;

    while ((ch = getopt(argc, argv, "ae:")) != EOF) {
        switch (ch) {
            case 'e':
                engine_count = atoi(optarg);
                break;
            case 'a':
                break;
            default:
                break;
        }
    }
    printf("optind = %d\n", optind);
    printf("engine_count = %d\n", engine_count);
    printf("argc = %d\n", argc);

    argc -= optind;
    argv += optind;

    int i;
    for (i = 0; i < argc; ++i)
        printf("%s\n", argv[i]);

    return 0;
}