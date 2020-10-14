//
// Created by jenson on 12-10-20.
//

#include "input.h"
static void proper_shutdown(SDL_Renderer *renderer, SDL_Window *window);

extern void process_input(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                proper_shutdown(renderer, window);
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                    proper_shutdown(renderer, window);
                    exit(0);
                }
                break;
            default:
                break;
        }
    }
}

static void proper_shutdown(SDL_Renderer *renderer, SDL_Window *window) {
    Mix_CloseAudio();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}