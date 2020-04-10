#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "lab2_file"

char *my_strpbrk(const char *s, const char *accept) {
    s += strcspn(s, accept);
    return *s ? (char*)s : NULL;
}

void error(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

void std_call(FILE *file, char **argv) {
    char *std_call_result = strpbrk(argv[1], argv[2]);

    if (std_call_result) {
	fprintf(file, 
		"strpbrk(): first matching character: %c\n",
		*std_call_result);
    } else {
	fprintf(file, "strpbrk(): no matching\n");
    }
}

void my_call(FILE *file, char **argv) {
    char *my_call_result = my_strpbrk(argv[1], argv[2]);

    if (my_call_result) {
	fprintf(file,
		"my_strpbrk(): first matching character: %c\n",
		*my_call_result);
    } else {
	fprintf(file, "my_strpbrk(): no matching\n");
    }
}

void writing(const char *file_name, char **argv) {
    FILE *file = fopen(file_name, "a");
    if (!file)
	error("error: can not open file for writing");

    std_call(file, argv);
    my_call(file, argv);

    fclose(file);
}

void reading(const char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (!file)
	error("error: can not open file for reading");

    while (1) {
	int c = fgetc(file);
	if (feof(file))
	    break;
	printf("%c", c);
    }

    // clear content of the file after previous session
    freopen(FILE_NAME, "w", stdout);

    fclose(file);
}

int main(int argc, char **argv) {
    if (argc < 3)
	error("usage: lab2 [STRING1] [STRING2]");

    writing(FILE_NAME, argv);
    reading(FILE_NAME);

    return 0;
}
