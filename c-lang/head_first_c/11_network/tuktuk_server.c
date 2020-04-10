#include "netstream.h"

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int listener_d;

void handle_shutdown(int sig) {
    if (listener_d) {
	close(listener_d);
    }
    fprintf(stderr, "\nGoodbye!\n");
    exit(0);
}

void catch_signal(int sig, void(*handler)(int)) {
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    if (sigaction(sig, &action, NULL) == -1) {
	error("Can not set the interrupt handler.");
    }
}

int main() {
    catch_signal(SIGINT, handle_shutdown);
    listener_d = open_listener_socket();
    bind_to_port(listener_d, 30000);
    listen_port(listener_d, 10);

    puts("Waiting for connection...");

    char buf[255];
    while (1) {
	int connect_d = connect_to_client(listener_d);

	if (!fork()) {
	    close(listener_d);

	    const char *msg = 
		"Server with Tuk-Tuk protocol\r\nVersion 1.0\r\nTuk-Tuk!\r\n>";
	    say(connect_d, msg);

	    read_in(connect_d, buf, sizeof(buf));
	    if (strncasecmp("Who is it?", buf, 10)) {
		say(connect_d, "You should say 'Who is it?'!\r\n");
	    } else {
		if (say(connect_d, "Death\r\n>") != -1) {
		    read_in(connect_d, buf, sizeof(buf));
		    if (strncasecmp("So what?", buf, 8)) {
			say(connect_d, "You should say 'So what?'!\r\n");
		    } else {
			say(connect_d, "That's all\r\n");
		    }
		}
	    }
	    close(connect_d);
	    exit(0);
	}
	close(connect_d);
    }

    return 0;
}
