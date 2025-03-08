#include "server.utils.h"

#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>

int setup_server_socket() {
    const int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in address;
    const int addrLen = sizeof(address);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    const int isBound = bind(server_fd, &address, addrLen);
    if (isBound < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);
    return server_fd;
}

void handle_client_message(int client_socket, fd_set *master_set) {

}

void log_message(const char *message) {

}

