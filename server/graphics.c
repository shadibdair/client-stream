#include <SDL2/SDL.h>

int test_sdl() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        fprintf(stderr, "SDL initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window
    SDL_Window *window = SDL_CreateWindow("Multimedia Player", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    if (!window) {
        fprintf(stderr, "Window creation failed: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    // Load a video or audio file (omitted here)

    // Main event loop
    SDL_Event event;
    int isPlaying = 0;

    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    // Handle window close event
                    SDL_Quit();
                    return 0;

                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_SPACE) {
                        // Toggle play/pause when the spacebar is pressed
                        isPlaying = !isPlaying;
                        if (isPlaying) {
                            // Start playback
                        } else {
                            // Pause playback
                        }
                    }
                    break;

                // Handle other events as needed
            }
        }

        // Update the screen and continue playback if isPlaying is true
        if (isPlaying) {
            // Update the video or audio playback (omitted in this basic example)
        }
    }

    // Cleanup and exit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
