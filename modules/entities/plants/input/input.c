//
// Created by jenson on 12-10-20.
//

#include "input.h"
static void proper_shutdown(SDL_Renderer *renderer, SDL_Window *window, TTF_Font *font);

extern void process_input(SDL_Window *window, SDL_Renderer *renderer, TTF_Font *font) {
    SDL_Event event;
    int mouseX;
    int mouseY;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                proper_shutdown(renderer, window, font);
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                SDL_GetMouseState(&mouseX,&mouseY);
//                handle_click(mouseX,mouseY);
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                    proper_shutdown(renderer, window, font);
                    exit(0);
                }
                break;
            default:
                break;
        }
    }
}

static void proper_shutdown(SDL_Renderer *renderer, SDL_Window *window, TTF_Font *font) {
    Mix_CloseAudio();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}