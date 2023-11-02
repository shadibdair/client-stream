#include "client_network.h"

int client_socket_init()
{
    int client_socket, rc;
    struct sockaddr_in server_addr;

    client_log(INF, "Initializing and configuring the client socket..\n");
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        client_log(ERR, "Socket creation failed.\n");
        return client_socket;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345); /* Todo: Change port, define it. */
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    client_log(INF, "Connecting to the server..\n");
    if ((rc = connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr))) < 0) {
        client_log(ERR, "Connection failed, return code %d.\n", rc);
        return rc;
    }

    return client_socket;
}

void video_data_receive(int client_socket)
{
    char buffer[1024];

    int bytes_read = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_read > 0) {
        buffer[bytes_read] = '\0';
        client_log(INF, "Received video data: %s\n", buffer);
    }
}