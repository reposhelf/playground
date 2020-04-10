#include "../include/netstream.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void error(const char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int open_listener_socket() {
    int listener_d = socket(PF_INET, SOCK_STREAM, 0);
    if (listener_d == -1) {
	error("Can not open socket for listening.");
    }
    return listener_d;
}

void bind_to_port(int socket, int port) {
    int reuse = 1;
    if (setsockopt(socket,
		   SOL_SOCKET,
		   SO_REUSEADDR,
		   (char *)&reuse,
		   sizeof(int)) == -1) {
	error("Can not set option for reuse of port.");
    }

    struct sockaddr_in name;
    name.sin_family = PF_INET;
    name.sin_port = (in_port_t)htons(port);
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    if ( bind(socket, (struct sockaddr *)&name, sizeof(name)) == -1) {
	error("Can not bind with port.");
    }
}

void listen_port(int socket, int clients_cnt) {
    if (listen(socket, clients_cnt) == -1)
	error("Can not listening port");
}

int connect_to_client(int socket) {
    struct sockaddr_storage client_addr;
    unsigned int addr_size = sizeof(client_addr);
    int connect_d = accept(socket,
			   (struct sockaddr *)&client_addr,
			   &addr_size);
    if (connect_d == -1) {
	error("Can not connect to second socket");
    }
    return connect_d;
}

int say(int socket, const char *msg) {
    int result = send(socket, msg, strlen(msg), 0);
    if ( result == -1) {
	fprintf(stderr,
		"%s: %s\n",
		"Error when communicating with the client",
		strerror(errno));
    }
    return result;
}

int read_in(int socket, char *buf, int len) {
    char *s = buf;
    int slen = len;
    int c = recv(socket, s, slen, 0);
    while ((c > 0) && (s[c - 1] != '\n')) {
	s += c;
	slen -= c;
	c = recv(socket, s, slen, 0);
    }
    if (c < 0) {
	return c;
    } else if (c == 0) {
	buf[0] = '\0';
    } else {
	s[c - 1] = '\0';
    }
    return len - slen;
}

int connect_to_server(int socket, const char *addr, int port) {
    struct sockaddr_in name;
    memset(&name, 0, sizeof(name));
    name.sin_family = PF_INET;
    name.sin_addr.s_addr = inet_addr(addr);
    name.sin_port = htons(port);
    int c = connect(socket, (struct sockaddr *)&name, sizeof(name));
    if (c == -1) {
	error("Can not open socket for connect to server");
    }
    return c;
}
