/*
* Utility functions that assist with various tasks with the server application.
*/

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <inttypes.h>

#define SERVER_DEBUG        1

enum log_levels {
    INF = 0,
    WRN,
    ERR,
    DBG
};

#define server_log(level, ...) \
    do { \
        switch (level) { \
            case ERR: \
                printf("[ERR]: " __VA_ARGS__); \
                break; \
            case WRN: \
                printf("[WARNING]: " __VA_ARGS__); \
                break; \
            case INF: \
                printf("[INFO]: " __VA_ARGS__); \
                break; \
            case DBG:  \
                if (SERVER_DEBUG) \
                    printf("[DEBUG]: " __VA_ARGS__); \
                break; \
        } \
    } while (0)

#endif /* UTILS_H */
