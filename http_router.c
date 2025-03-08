#include "http_router.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

/** Enum for route identifiers */
typedef enum {
    ROUTE_HOME,
    ROUTE_HELLO,
    ROUTE_ABOUT,
    ROUTE_NOT_FOUND
} Route;

/** 🔹 Extracts path from request */
Route get_route(const char *request) {
    if (strstr(request, "GET / HTTP/1.1")) {
        return ROUTE_HOME;
    } else if (strstr(request, "GET /hello HTTP/1.1")) {
        return ROUTE_HELLO;
    } else if (strstr(request, "GET /about HTTP/1.1")) {
        return ROUTE_ABOUT;
    } else {
        return ROUTE_NOT_FOUND;
    }
}


/** Sends an HTTP response */
void send_response(const int client_socket, const char *status, const char *content_type, const char *body) {
    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);

    snprintf(response, sizeof(response),
             "HTTP/1.1 %s\r\n"
             "Content-Type: %s\r\n"
             "Content-Length: %zu\r\n"
             "Connection: close\r\n\r\n"
             "%s",
             status, content_type, strlen(body), body);

    send(client_socket, response, strlen(response), 0);
    memset(response, 0, BUFFER_SIZE);
}


/** Routes incoming HTTP requests */
void route_request(const int client_socket, const char *request) {
    switch (get_route(request)) {
        case ROUTE_HOME:
            send_response(client_socket, "200 OK", "text/plain", "Welcome to the home page!");
            break;
        case ROUTE_HELLO:
            send_response(client_socket, "200 OK", "text/plain", "Hello, World!");
            break;
        case ROUTE_ABOUT:
            send_response(client_socket, "200 OK", "text/plain", "This is a basic HTTP server.");
            break;
        case ROUTE_NOT_FOUND:
        default:
            send_response(client_socket, "404 Not Found", "text/plain", "404 - Page not found.");
            break;
    }
}