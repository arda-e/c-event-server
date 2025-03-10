#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <sys/event.h>
#include "server.utils.h"

int create_kqueue_instance() {
    const int kq = kqueue();
    if (kq == -1) {
        perror("Failed to create kqueue instance");
        exit(EXIT_FAILURE);
    }
    return kq;
}

void handle_events(int server_fd, int kq) {
    struct kevent events[MAX_EVENTS];
    while (1) {
        const int n_events = kevent(kq, NULL, 0, events, MAX_EVENTS,  NULL);

        if (n_events == -1) {
            if (errno == EINTR) {
                continue; // interrupted by signal, continue the loop
            }
            perror("Error in kevent");
            exit(EXIT_FAILURE);
        }
    }
}

/**
 * Registers an event with kqueue.
 *
 * @param kq The kqueue instance file descriptor.
 * @param socket_fd The socket file descriptor to monitor.
 * @param filter The type of event to monitor (EVFILT_READ or EVFILT_WRITE).
 * @param flags Additional flags (EV_ADD, EV_ONESHOT, etc.).
 */
void register_kqueue_event(int kq, int socket_fd, int filter, int flags) {
    struct kevent event;
    EV_SET(&event, socket_fd, filter, flags, 0, 0, NULL);

    if (kevent(kq, &event, 1, NULL, 0, NULL) == -1) {
        perror("Failed to register kqueue event");
        exit(EXIT_FAILURE);
    }
}
