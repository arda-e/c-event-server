#include "http_helpers.h"
#include "http_router.h"
#include <stdio.h>

#include <sys/socket.h>

#define BUFFER_SIZE 1024

/**
 * Parses the HTTP request received on the given client socket.
 *
 * This function reads the request data from the client socket, prints the
 * received request to the console, and then passes the request to the
 * `route_request` function for further processing.
 *
 * @param client_socket The client socket to read the request from.
 */
void parse_request(int client_socket) {
    char buffer[BUFFER_SIZE] = {0};
    const int bytes_read = recv(client_socket, buffer, sizeof(buffer) - 1, 0);

    if (bytes_read > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate request
        printf("[LOG] Received Request:\n%s\n", buffer);
        route_request(client_socket, buffer);
    }
}
