#include "client_ui.h"

static SDL_Rect play_button;
static SDL_Rect pause_button;
static SDL_Rect stop_button;
static SDL_Rect volume_slider;

static struct button buttons[TOTAL_BUTTON_NUM];

/* Init the UI elemenets */
void ui_elements_init()
{
    /* Todo: Change the magic numbers, fit to screen. */
    int button_width = 100;
    int button_height = 40;
    int margin = 20;

    client_log(DBG, "Initializing UI elements.\n");

    play_button.x = margin;
    play_button.y = margin;
    play_button.w = button_width;
    play_button.h = button_height;

    // Position and size of the Pause button
    pause_button.x = margin * 2 + button_width;
    pause_button.y = margin;
    pause_button.w = button_width;
    pause_button.h = button_height;

    // Position and size of the Stop button
    stop_button.x = margin * 3 + button_width * 2;
    stop_button.y = margin;
    stop_button.w = button_width;
    stop_button.h = button_height;

    // Position and size of the Volume slider (example)
    volume_slider.x = margin;
    volume_slider.y = margin * 2 + button_height;
    volume_slider.w = button_width * 3 + margin * 2;
    volume_slider.h = button_height;

    buttons_init();
}

void buttons_init()
{
    client_log(DBG, "Initializing buttons.\n");
    buttons[PLAY_BUTTON] = (struct button) {
        .rect = play_button,
        .on_click_action = play_click_handle
    };

    buttons[PAUSE_BUTTON] = (struct button) {
        .rect = pause_button,
        .on_click_action = pause_click_handle
    };

    buttons[STOP_BUTTON] = (struct button){
        .rect = stop_button,
        .on_click_action = stop_click_handle
    };
}

/* Renders UI elements 
 * Todo: Make it more efficient, avoid unnecessary rendering calls (i.e if UI elements haven't 
 * changed) */
void ui_elements_render(SDL_Renderer* renderer)
{
    /* Clear the renderer */
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    /* Render the buttons */
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &play_button);
    SDL_RenderFillRect(renderer, &pause_button);
    SDL_RenderFillRect(renderer, &stop_button);

    /* Render the volume slider (example) */
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    SDL_RenderFillRect(renderer, &volume_slider);

    /* Present the renderer */
    SDL_RenderPresent(renderer);
}

/* Implements event handling for button clicks and other UI interactions */
void ui_elements_handle(SDL_Event e)
{
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        int mouse_x, mouse_y;
        SDL_GetMouseState(&mouse_x, &mouse_y);

        SDL_Point mouse_point = { mouse_x, mouse_y };

        for (int i = 0; i < ARRAY_LENGTH(buttons); i++) {
            if (SDL_PointInRect(&mouse_point, &buttons[i].rect)) {
                buttons[i].on_click_action();
                break;
            }
        }
    }
}

void play_click_handle()
{            
    client_log(DBG, "Play button pressed.\n");
}

void pause_click_handle()
{
    client_log(DBG, "Pause button pressed.\n");
}

void stop_click_handle()
{
    client_log(DBG, "Stop button pressed.\n");
}
