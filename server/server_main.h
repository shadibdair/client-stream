#ifndef SERVER_MAIN_H
#define SERVER_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>

#include "server_network.h"
#include "utils.h"

enum server_exit_value {
    SERVER_EXIT_PASS        = 0,
    SERVER_EXIT_FAIL        = 1,
    SERVER_EXIT_FAIL_INIT   = 2,
    SERVER_EXIT_FAIL_LOGIC  = 3,
};

#endif /* SERVER_MAIN_H */