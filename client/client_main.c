#include "client_main.h"

int main(int argc, char *argv[]) 
{
    int client_socket;

    sdl_init();
    // client_socket = client_socket_init();
    // if (client_socket < 0) {
    //     sdl_close();
    //     exit(CLIENT_EXIT_FAIL_INIT);
    // }

    // video_data_receive(client_socket);
    sdl_event_loop_run();

    // video_play(buffer, sizeof(buffer));

    // close(client_socket);
    sdl_close();
    return CLIENT_EXIT_PASS;
}