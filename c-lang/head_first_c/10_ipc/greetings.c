#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_interrupt(int sig) {
    puts("\nGoodbye, cruel world :(\n");
    exit(1);
}

int catch_signal(int sig, void(*handler)(int)) {
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction(sig, &action, NULL);
}

int main() {
    if (catch_signal(SIGINT, handle_interrupt) == -1) {
	fprintf(stderr, "Can not find handler\n");
	exit(2);
    }

    char name[30];
    puts("Enter your name: ");
    fgets(name, 30, stdin);
    printf("Hello, %s\n", name);

    return 0;
}
