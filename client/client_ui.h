/*
* Implement user controls for play, pause, stop, volume, quality, and any other user interactions. 
* This module also communicates user commands to the network component.
*/

#ifndef CLIENT_UI_H
#define CLIENT_UI_H

#include <SDL2/SDL.h>

#include "utils.h"

struct button {
    SDL_Rect rect;
    void (*on_click_action)();
};

enum button_types {
    PLAY_BUTTON = 0,
    PAUSE_BUTTON,
    STOP_BUTTON,

    TOTAL_BUTTON_NUM
};

void ui_elements_init();
void buttons_init();
void ui_elements_render(SDL_Renderer* renderer);
void ui_elements_handle(SDL_Event e);
void play_click_handle();
void pause_click_handle();
void stop_click_handle();

#endif /* CLIENT_UI_H */