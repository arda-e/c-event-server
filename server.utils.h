#ifndef SERVER_UTILS_H
#define SERVER_UTILS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/select.h>


#define PORT 8080
#define BUFFER_SIZE 1024

#define MAX_CLIENTS 10
#define MAX_EVENTS 64

#define PREFIX "Server: "

/* Socket creation and setup functions */
int create_socket();
void setup_address(struct sockaddr_in *address, int port);
void bind_socket(int server_fd, struct sockaddr_in *address);
void listen_on_socket(int server_fd, int backlog);
int setup_server_socket();

/* Client connection handling functions */
int accept_client_connection(int server_fd, struct sockaddr_in *client_addr, socklen_t *addr_len);
bool handle_client_connection(int client_socket);
void handle_client_message(int client_socket, fd_set *master_set);

/* Utility functions */
void log_message(const char *message);
void close_socket(const int socket_fd);

#endif //SERVER_UTILS_H
