/*
* Implement user controls for play, pause, stop, volume, quality, and any other user interactions. 
* This module also communicates user commands to the network component.
*/

#ifndef CLIENT_UI_H
#define CLIENT_UI_H

#include <SDL2/SDL.h>

#include "utils.h"

#define BUTTON_WIDTH        100
#define BUTTON_HEIGHT       40
#define MARGIN              20

struct button {
    SDL_Rect *rect;
    void (*on_click_action)();
};

enum button_types {
    PLAY_BUTTON = 0,
    PAUSE_BUTTON,
    STOP_BUTTON,

    TOTAL_BUTTON_NUM
};

void ui_elements_init(SDL_Window *window);
void buttons_init();
void button_positions_set(SDL_Window *window);
void ui_elements_render(SDL_Renderer* renderer);
void ui_elements_handle(SDL_Event e);
void play_click_handle();
void pause_click_handle();
void stop_click_handle();

#endif /* CLIENT_UI_H */