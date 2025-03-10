#include <stdbool.h>
#include <sys/event.h>
#include "server.utils.h"
#include "event_loop/event_loop.h"


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


    const int loop_fd = event_loop_create();
    event_loop_register_event(loop_fd, server_fd, EVFILT_READ, EV_ADD | EV_ENABLE);
    event_loop_run(server_fd, loop_fd);

    /* Close the server socket when exiting the program */
    close(loop_fd);
    close(server_fd);
    return 0;
}


