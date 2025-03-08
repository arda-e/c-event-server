#include "server.utils.h"
int main() {
    const int server_fd = setup_server_socket();
    close(server_fd);
    return 0;
}