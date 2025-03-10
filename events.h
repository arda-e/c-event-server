//
// Created by arda on 8.03.2025.
//

#ifndef EVENTS_H
#define EVENTS_H

/**
* Creates a new kqueue instance.
 *
 * @return File descriptor for the new kqueue instance.
 */
int create_kqueue_instance();

void handle_events(int server_fd, int kq);

/**
 * Registers an event with kqueue.
 *
 * @param kq The kqueue instance file descriptor.
 * @param socket_fd The socket file descriptor to monitor.
 * @param filter The type of event to monitor (EVFILT_READ or EVFILT_WRITE).
 * @param flags Additional flags (EV_ADD, EV_ONESHOT, etc.).
 */
void register_kqueue_event(int kq, int socket_fd, int filter, int flags);

#endif //EVENTS_H
