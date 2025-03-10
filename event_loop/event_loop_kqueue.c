#include <stdio.h>
#include <_stdlib.h>
#include <sys/event.h>
#include "event_loop.h"
#include "../server.utils.h"

int event_loop_create(void) {
    const int kq = kqueue();
    if (kq == -1) {
        perror("Failed to create kqueue");
        exit(EXIT_FAILURE);
    }
    return kq;
}

const char* event_loop_get_backend_name(void) {
    return "kqueue";
}

void event_loop_register_event(int loop_fd, int socket_fd, int filter, int flags) {
    struct kevent event;
    EV_SET(&event, socket_fd, filter, flags, 0, 0, NULL);
    if (kevent(loop_fd, &event, 1, NULL, 0, NULL) == -1) {
        perror("Failed to register kqueue event");
        exit(EXIT_FAILURE);
    }
}

void event_loop_run(int server_fd, int loop_fd) {
    while (1) {
        struct kevent events[MAX_EVENTS];
        const int n_events = kevent(loop_fd, NULL, 0, events, MAX_EVENTS, NULL);
        if (n_events == -1) {
            perror("Failed to wait for events");
            exit(EXIT_FAILURE);
        }
    }
}