#include "client_ui.h"

static SDL_Rect play_button;
static SDL_Rect pause_button;
static SDL_Rect stop_button;
static SDL_Rect volume_slider;

static bool is_changed;

static struct button buttons[TOTAL_BUTTON_NUM];

/* Init the UI elemenets */
void ui_elements_init(SDL_Window *window)
{
    client_log(DBG, "Initializing UI elements.\n");

    button_positions_set(window);
    buttons_init();
}

void buttons_init()
{
    client_log(DBG, "Initializing buttons.\n");
    buttons[PLAY_BUTTON] = (struct button) {
        .rect = &play_button,
        .on_click_action = play_click_handle
    };

    buttons[PAUSE_BUTTON] = (struct button) {
        .rect = &pause_button,
        .on_click_action = pause_click_handle
    };

    buttons[STOP_BUTTON] = (struct button) {
        .rect = &stop_button,
        .on_click_action = stop_click_handle
    };
}

void button_positions_set(SDL_Window *window)
{
    int window_width, window_height;
    int total_button_width, x_centered;

    is_changed = true;

    SDL_GetWindowSize(window, &window_width, &window_height);

    total_button_width = 3 * BUTTON_WIDTH + 2 * MARGIN;
    x_centered = (window_width - total_button_width) / 2;

    /* Position and size the buttons */
    play_button.x = x_centered;
    play_button.y = window_height - BUTTON_HEIGHT - MARGIN;
    play_button.w = BUTTON_WIDTH;
    play_button.h = BUTTON_HEIGHT;

    pause_button.x = x_centered + BUTTON_WIDTH + MARGIN;
    pause_button.y = window_height - BUTTON_HEIGHT - MARGIN;
    pause_button.w = BUTTON_WIDTH;
    pause_button.h = BUTTON_HEIGHT;

    stop_button.x = x_centered + 2 * (BUTTON_WIDTH + MARGIN);
    stop_button.y = window_height - BUTTON_HEIGHT - MARGIN;
    stop_button.w = BUTTON_WIDTH;
    stop_button.h = BUTTON_HEIGHT;

    /* Todo: Perhaps change position */
    volume_slider.x = MARGIN;
    volume_slider.y = play_button.y;
    volume_slider.w = BUTTON_WIDTH * 2;
    volume_slider.h = BUTTON_HEIGHT;
}

/* Renders UI elements 
 * Todo: Make it more efficient, avoid unnecessary rendering calls (i.e if UI elements haven't 
 * changed) 
 * Add PLAY/PAUSE/STOP on the buttons. */
void ui_elements_render(SDL_Renderer* renderer)
{
    if (!is_changed)
        return;

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

    is_changed = false;
}

/* Implements event handling for button clicks and other UI interactions */
void ui_elements_handle(SDL_Event event)
{
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        int mouse_x, mouse_y;
        SDL_GetMouseState(&mouse_x, &mouse_y);

        SDL_Point mouse_point = { mouse_x, mouse_y };

        for (int i = 0; i < ARRAY_LENGTH(buttons); i++) {
            if (SDL_PointInRect(&mouse_point, buttons[i].rect)) {
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
