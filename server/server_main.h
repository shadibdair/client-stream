#ifndef SERVER_MAIN_H
#define SERVER_MAIN_H

enum server_exit_value {
    SERVER_EXIT_PASS        = 0,
    SERVER_EXIT_FAIL        = 1,
    SERVER_EXIT_FAIL_INIT   = 2,
    SERVER_EXIT_FAIL_LOGIC  = 3,
};

#endif /* SERVER_MAIN_H */