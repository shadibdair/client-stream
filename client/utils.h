/*
* Utility functions that assist with various tasks with the client application.
*/

#ifndef UTILS_H
#define UTILS_H

#include <inttypes.h>
#include <stdbool.h>

#define CLIENT_DEBUG 1

enum log_levels {
    INF = 0,
    WRN,
    ERR,
    DBG
};

#define client_log(level, ...) \
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
                if (CLIENT_DEBUG) \
                    printf("[DEBUG]: " __VA_ARGS__); \
                break; \
        } \
    } while (0)

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof((x)[0]))

#endif /* UTILS_H */