#include "http_helpers.h"
#include "server.utils.h"

int main() {
    const int server_fd = setup_server_socket();

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        memset(&client_addr, 0, addr_len);

        int const client_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);

        if (client_socket < 0) {
            perror("Failed to accept client connection");
            continue;
        }

        printf("Client connected!\n");
        parse_request(client_socket);

        close(client_socket);
        printf("Client disconnected.\n");
    }

    close(server_fd);
    return 0;
}