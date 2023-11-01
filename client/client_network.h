/*
* This module deals with setting up a network connection to the server, 
* sending and receiving RTP packets, and handling network-related tasks.
*/

#ifndef CLIENT_NETWORK_H
#define CLIENT_NETWORK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "utils.h"

int client_socket_init();
void video_data_receive(int client_socket);

#endif /* CLIENT_NETWORK_H */