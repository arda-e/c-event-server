#include <stdbool.h>
#include <sys/event.h>

#include "server.utils.h"
#include "events.h"


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

    const int kq = create_kqueue_instance();
    register_kqueue_event(kq, server_fd, EVFILT_READ, EV_ADD | EV_ENABLE);
    handle_events(server_fd, kq);

    /* Close the server socket when exiting the program */
    close(kq);
    close(server_fd);
    return 0;
}


