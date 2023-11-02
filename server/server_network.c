#include "server_network.h"

int server_socket_init()
{
    int server_socket, rc;
    struct sockaddr_in server_addr;

    log(INF, "Initializing socket..\n");
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        log(ERR, "Socket creation failed.\n");
        return server_socket;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345); /* Todo: Change the port to a defined value. */
    server_addr.sin_addr.s_addr = INADDR_ANY;

    log(INF, "Binding socket..\n");
    if ((rc = bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr))) < 0) {
        log(ERR, "Binding failed, return code %d.\n", rc);
        return rc;
    }

    /* Todo: Change 5 to constant number. Perhaps it's different if we apply parallelism. */
    listen(server_socket, 5);
    log(INF, "Server is listening on port 12345..\n"); /* Todo: Add info on listening port etc. */

    return server_socket;
}


int client_accept(int server_socket)
{
    int client_socket;
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);

    client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_len);
    return client_socket;
}

void send_video_data(int client_socket)
{
    char video_data[] = "Sample video data";
    log(INF, "Sending sample video data to client.\n");
    send(client_socket, video_data, strlen(video_data), 0);
}