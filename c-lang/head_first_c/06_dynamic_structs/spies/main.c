#include "spies.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char question[80];
    char suspect[40];
    node *start_node = create("Does suspect wear a mustache?");
    start_node->no = create("Loretta Barnshwarts");
    start_node->yes = create("Ivan Lozhkin");

    node *current;
    do {
        current = start_node;
        while (1) {
            if (yes_no(current->question)) {
                if (current->yes) {
                    current = current->yes;
                } else {
                    printf("SUSPECT FOUND\n");
                    break;
                }
            } else if (current->no) {
                current = current->no;
            } else {
                printf("Who is suspect? ");
                fgets(suspect, 40, stdin);
                node *yes_node = create(suspect);
                current->yes = yes_node;

                node *no_node = create(current->question);
                current->no = no_node;

                printf("Give me a question, that's true for %s, but not for %s. ", suspect, current->question);
                fgets(question, 80, stdin);
                free(current->question);
                current->question = strdup(question);

                break;
            }
        }
    } while (yes_no("Do it again"));
    release(start_node);
    return 0;
}