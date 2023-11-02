/*
* This code is responsible for the graphical user interface of client applications
* using the SDL library.
*/

#ifndef CLIENT_GUI_H
#define CLIENT_GUI_H

#include <SDL2/SDL.h>

#include "client_ui.h"
#include "utils.h"

#define WIN_DELIM           1.5

int sdl_init();
void sdl_close();
void sdl_event_loop_run();

#endif /* CLIENT_GUI_H */