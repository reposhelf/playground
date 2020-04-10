#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 6) {
        fprintf(stderr, "You must send 5 arguments");
        return 1;
    }

    FILE *in_file;
    if (!(in_file = fopen("spooky.csv", "r"))) {
        fprintf(stderr, "Can't open file\n");
        return 1;
    }
    FILE *file1 = fopen(argv[2], "w");
    FILE *file2 = fopen(argv[4], "w");
    FILE *file3 = fopen(argv[5], "w");
    char line[80];

    while (fscanf(in_file, "%79[^\n]\n", line) == 1) {
        if (strstr(line, argv[1]))
            fprintf(file1, "%s\n", line);
        else if (strstr(line, argv[3]))
            fprintf(file2, "%s\n", line);
        else
            fprintf(file3, "%s\n", line);
    }

    fclose(file1);
    fclose(file2);
    fclose(file3);

    return 0;
}