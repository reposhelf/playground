#include "netstream.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *advice[] = {
	"Eat smaller portions.\r\n",
	"Buy tight jeans. No, you do not look fat.\r\n",
	"Single word: wrong.\r\n",
	"Be honest with yourself.\r\n",
	"Maybe you need new hairstyle.\r\n"
    };

    int listener_d = open_listener_socket();
    bind_to_port(listener_d, 30000);
    listen_port(listener_d, 10);
    puts("Waiting for connection");

    while (1) {
	int connect_d = connect_to_client(listener_d);
	const char *msg = advice[rand() % 5];
	say(connect_d, msg);
	close(connect_d);
    }

    return 0;
}
