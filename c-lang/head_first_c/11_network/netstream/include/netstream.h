#ifndef NETSTREAM_H
#define NETSTREAM_H

void error(const char *msg);
int open_listener_socket();
void bind_to_port(int socket, int port);
void listen_port(int socket, int clients_cnt);
int connect_to_client(int socket);
int say(int socket, const char *msg);
int read_in(int socket, char *buf, int len);
int connect_to_server(int socket, const char *addr, int port);

#endif
