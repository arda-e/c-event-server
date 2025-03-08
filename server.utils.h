
#ifndef SERVER_UTILS_H
#define SERVER_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/select.h>v

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10
#define PREFIX "Server: "

int setup_server_socket();
void handle_client_message(int client_socket, fd_set *master_set);
void log_message(const char *message);

#endif //SERVER_UTILS_H
