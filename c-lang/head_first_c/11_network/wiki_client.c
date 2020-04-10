#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void error(const char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(0);
}

int open_socket(const char *host, const char *port) {
    struct addrinfo *res;
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = PF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(host, port, &hints, &res) == -1) {
	error("Can not resolve address");
    }
    int d_sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (d_sock == -1) {
	error("Can not open socket");
    }
    int c = connect(d_sock, res->ai_addr, res->ai_addrlen);
    freeaddrinfo(res);
    if (c == -1) {
	error("Can not connect to socket");
    }
    return d_sock;
}

int say(int socket, const char *msg) {
    int result = send(socket, msg, strlen(msg), 0);
    if (result == -1) {
	fprintf(stderr,
		"Error of comminacation with server: %s\n",
		strerror(errno));
    }
    return result;
}

int main(int argc, char **argv) {
    int d_sock = open_socket("en.wikipedia.org", "80");

    char buff[256];
    sprintf(buff, "GET /wiki/%s http/1.1\r\n", argv[1]);
    say(d_sock, buff);
    say(d_sock, "Host: https://en.wikipedia.org\r\n\r\n");

    char rec[256];
    int bytes_rcvd = recv(d_sock, rec, 256, 0);
    while (bytes_rcvd) {
	if (bytes_rcvd == -1) {
	    error("Can not get data from server");
	}
	rec[bytes_rcvd] = '\0';
	printf("%s", rec);
	bytes_rcvd = recv(d_sock, rec, 256, 0);
    }
    close(d_sock);

    return 0;
}
