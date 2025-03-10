//
// Created by arda on 10.03.2025.
//

#ifndef EVENT_LOOP_H
#define EVENT_LOOP_H

/**
 * Creates a new event loop instance.
 *
 * @return Instance handle (file descriptor) for the event loop
 */
int event_loop_create(void);


/**
 * Get backend implementation name
 *
 * @return Name of the current backend implementation
 */
const char* event_loop_get_backend_name(void);

/**
 * Registers an event with the event loop.
 *
 * @param loop_fd The event loop handle/fd
 * @param socket_fd The socket file descriptor to monitor
 * @param filter The type of event to monitor
 * @param flags Additional flags for the event
 */
void event_loop_register_event(int loop_fd, int socket_fd, int filter, int flags);

/**
 * Runs the event loop and handles events.
 *
 * @param server_fd The server socket to handle connections for
 * @param loop_fd The event loop handle/fd
 */
void event_loop_run(int server_fd, int loop_fd);


#endif //EVENT_LOOP_H
