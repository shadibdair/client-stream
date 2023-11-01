#include "client_main.h"

int main(int argc, char *argv[]) 
{
    int client_socket;

    client_socket = client_socket_init();
    if (client_socket < 0)
        exit(CLIENT_EXIT_FAIL_INIT);

    video_data_receive(client_socket);

    // video_play(buffer, sizeof(buffer));

    close(client_socket);
    return CLIENT_EXIT_PASS;
}