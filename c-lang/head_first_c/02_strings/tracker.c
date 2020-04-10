#include <stdio.h>
#include <string.h>

char tracks[][80] = {
    "I left my heart in the Harvard Medical School",
    "Newark, Newark - a city full of wonders",
    "A dork dance",
    "From here to the hospital",
    "Girl from the island of Iwo Jima"
};

char *find_track(const char *search_for)
{
    int i;
    for (i = 0; i < 5; ++i) {
        if (strstr(tracks[i], search_for))
            return tracks[i];
    }
    return NULL;
}

int main()
{
    char search_for[80];
    printf("Search: ");
    fgets(search_for, 80, stdin);
    search_for[strlen(search_for) - 1] = '\0';
    char *res = find_track(search_for);
    printf("Now playing \"%s\"\n", res);
    return 0;
}
