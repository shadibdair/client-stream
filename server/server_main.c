#include "server_main.h"

int main(int argc, char *argv[]) 
{
    int server_socket, client_socket;

    /* Todo: Add support to multiple clients. */

    server_socket = server_socket_init();
    if (server_socket < 0)
        exit(SERVER_EXIT_FAIL_INIT);

    client_socket = client_accept(server_socket);
    send_video_data(client_socket);

    close(client_socket);
    close(server_socket);

    return SERVER_EXIT_PASS;
}


