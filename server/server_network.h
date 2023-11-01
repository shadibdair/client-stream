/*
* This module deals with setting up a network socket to listen for client connections, 
* accepting client connections, and managing network communication. It includes socket 
* handling and using an appropriate library.
*/


#ifndef SERVER_NETWORK_H
#define SERVER_NETWORK_H

#include "server_main.h"

/* potentially using a library like libevent or libuv.
   REMOVE AND UPDATE ONCE WE REALIZE. */
   int server_socket_init();
   int client_accept(int server_socket);
   void send_video_data(int client_socket);

#endif /* SERVER_NETWORK_H */