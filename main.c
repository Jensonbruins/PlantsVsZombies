#include "modules.h"
#include "sdl.h"
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    unsigned int window_flags = 0;
    unsigned int renderer_flags = SDL_RENDERER_ACCELERATED;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    } window = SDL_CreateWindow("Blorp is going to F U UP!",
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                              SCREEN_HEIGHT, window_flags);
    if (window == NULL) {
        printf("Failed to create window -- Error: %s\n",
               SDL_GetError());
        exit(1);
    }
    renderer = SDL_CreateRenderer(window, -1, renderer_flags);
    if (renderer == NULL) {
        printf("Failed to create renderer -- Error: %s\n",
               SDL_GetError());
        exit(1);
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
        printf("Failed to create mixer -- Error: %s\n", SDL_GetError());
        exit(1);
    }

    int Fps = 60;
    unsigned int firstFrame;
    unsigned int frameTime;
    while (1) {
        firstFrame = SDL_GetTicks();
        SDL_SetRenderDrawColor(renderer, 120, 144, 156, 255);
        SDL_RenderClear(renderer);

        process_input(window, renderer);

        SDL_RenderPresent(renderer);
        frameTime = SDL_GetTicks() - firstFrame;
        if (1000 / (unsigned int) Fps> frameTime) {
            SDL_Delay(1000 / (unsigned int) Fps - frameTime);
        }
    }
}