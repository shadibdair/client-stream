#include "client_gui.h"

static SDL_Window *g_window;
static SDL_Renderer *g_renderer;

/* Todo: Handle errors. Maybe return enum of error codes instead. */
int sdl_init()
{
    client_log(INF, "Initializing SDL..\n");
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        client_log(ERR, "SDL initialization failed: %s\n", SDL_GetError());
        return -1;
    }

    client_log(INF, "Creating SDL window and renderer..\n");
    g_window = SDL_CreateWindow("Video Player", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                                800, 600, SDL_WINDOW_SHOWN);
    if (g_window == NULL) {
        client_log(ERR, "Window creation failed: %s\n", SDL_GetError());
        return -1;
    }

    g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
    if (g_renderer == NULL) {
        client_log(ERR, "Renderer creation failed: %s\n", SDL_GetError());
        return -1;
    }
    client_log(INF, "Window and renderer created successfully.\n");

    return 0;
}

void sdl_close()
{
    SDL_DestroyRenderer(g_renderer);
    SDL_DestroyWindow(g_window);

    SDL_Quit();
}

void sdl_event_loop_run()
{
    SDL_Event e;
    int quit = 0;

    ui_elements_init();

    client_log(INF, "In SDL event loop.\n");
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                client_log(DBG, "SDL QUIT pressed.\n");
                quit = 1;
            }
            ui_elements_handle(e);
            /* Handle other events as needed */
        }
        /* Implement custom logic here */
        ui_elements_render(g_renderer);

        /* Todo: Perhaps remove the following, added to reduce CPU usage for now. */
        SDL_Delay(10);
    }
}