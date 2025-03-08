#include "server.utils.h"

#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>

#include "http_helpers.h"

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

/**
 * Closes the specified socket and prints a message indicating that the client has disconnected.
 *
 * @param socket_fd The file descriptor of the socket to be closed.
 */
void close_socket(const int socket_fd) {
    close(socket_fd);
    printf("Client disconnected.\n");
}

/**
 * Handles a client connection by validating the socket and processing the request.
 *
 * @param client_socket The file descriptor of the client socket.
 * @return true if the connection was handled successfully, false otherwise.
 */
bool handle_client_connection(int client_socket) {
    if (client_socket < 0) {
        perror("Failed to accept client connection");
        return false;
    }

    printf("Client connected!\n");
    parse_request(client_socket);
    return true;
}

/**
 * Accepts a client connection on the specified server socket.
 *
 * @param server_fd The file descriptor of the server socket.
 * @param client_addr Pointer to a sockaddr_in structure to store client address information.
 * @param addr_len Pointer to the size of the client_addr structure.
 * @return The client socket file descriptor if successful, -1 otherwise.
 */
int accept_client_connection(int server_fd, struct sockaddr_in *client_addr, socklen_t *addr_len) {
    /* Initialize the client_addr structure with zeros */
    memset(client_addr, 0, *addr_len);

    /* Accept an incoming connection from a client and get the socket descriptor */
    return accept(server_fd, (struct sockaddr *)client_addr, addr_len);
}

/**
 * Creates a new socket for TCP/IP communication.
 *
 * @return The file descriptor of the created socket.
 */
int create_socket() {
    const int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    return server_fd;
}

/**
 * Sets up the socket address structure.
 *
 * @param address Pointer to the address structure to be set up.
 * @param port The port number to bind to.
 */
void setup_address(struct sockaddr_in *address, int port) {
    address->sin_family = AF_INET;
    address->sin_addr.s_addr = INADDR_ANY;
    address->sin_port = htons(port);
}

/**
 * Binds the socket to the specified address.
 *
 * @param server_fd The file descriptor of the server socket.
 * @param address Pointer to the address structure.
 */
void bind_socket(const int server_fd, struct sockaddr_in *address) {
    const int addrLen = sizeof(*address);
    const int isBound = bind(server_fd, (struct sockaddr *)address, addrLen);
    if (isBound < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }
}

/**
 * Starts listening for incoming connections on the socket.
 *
 * @param server_fd The file descriptor of the server socket.
 * @param backlog The maximum length of the queue of pending connections.
 */
void listen_on_socket(const int server_fd, const int backlog) {
    if (listen(server_fd, backlog) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
}


