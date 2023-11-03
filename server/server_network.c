#include "server_network.h"

int server_socket_init()
{
    int server_socket, rc;
    struct sockaddr_in server_addr;

    server_log(INF, "Initializing socket..\n");
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        server_log(ERR, "Socket creation failed.\n");
        return server_socket;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345); /* Todo: Change the port to a defined value. */
    server_addr.sin_addr.s_addr = INADDR_ANY;

    server_log(INF, "Binding socket..\n");
    if ((rc = bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr))) < 0) {
        server_log(ERR, "Binding failed, return code %d.\n", rc);
        return rc;
    }

    /* Todo: Change 5 to constant number. Perhaps it's different if we apply parallelism. */
    listen(server_socket, 5);
    server_log(INF, "Server is listening on port 12345..\n"); /* Todo: Add info on listening port etc. */

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

// void send_video_data(int client_socket)
// {
//     char video_data[] = "Sample video data";
//     server_log(INF, "Sending sample video data to client.\n");
//     send(client_socket, video_data, strlen(video_data), 0);
// }

void send_video_data(int client_socket)
{
    // Initialize video streaming
    if (video_streaming_init() != 0) {
        server_log(ERR, "Failed to initialize video streaming.\n");
        return;
    }

    /* Todo: We need to use RTP protocol to stream multimedia data. It provides time-stamping for
     * synchronization. RTP typically handles this by providing sequence numbers and timestamps.
     * On the client-side we need to receive, demultiplex, decode and render both video and audio
     * streams in real time. We will use SDL & GStreamer for that.
     * Take into account error handling. 
     * */
}

