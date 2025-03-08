#include "http_helpers.h"
#include "http_router.h"
#include <stdio.h>

#include <sys/socket.h>

#define BUFFER_SIZE 1024

void parse_request(int client_socket) {
    char buffer[BUFFER_SIZE] = {0};
    const int bytes_read = recv(client_socket, buffer, sizeof(buffer) - 1, 0);

    if (bytes_read > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate request
        printf("[LOG] Received Request:\n%s\n", buffer);
        route_request(client_socket, buffer);
    }
}
