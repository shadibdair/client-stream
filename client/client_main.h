#ifndef CLIENT_MAIN_H
#define CLIENT_MAIN_H

#include <stdio.h>

#include "client_network.h"
#include "client_video.h"
#include "utils.h"

enum client_exit_value {
    CLIENT_EXIT_PASS        = 0,
    CLIENT_EXIT_FAIL        = 1,
    CLIENT_EXIT_FAIL_INIT   = 2,
    CLIENT_EXIT_FAIL_LOGIC  = 3,
};

#endif /* CLIENT_MAIN_H*/