#include <stdbool.h>
#include "server.utils.h"



int main() {
    // Create a new socket
    const int server_fd = create_socket();

    // Set up address structure
    struct sockaddr_in address;
    setup_address(&address, PORT);

    // Bind the socket to the address
    bind_socket(server_fd, &address);

    // Start listening for connections
    listen_on_socket(server_fd, 3);

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);

        int const client_socket = accept_client_connection(server_fd, &client_addr, &addr_len);

        if (handle_client_connection(client_socket)) {
            close_socket(client_socket);
        }
    }

    /* Close the server socket when exiting the program */
    close(server_fd);
    return 0;
}


