/*
 *  @since: v1.0.0
 *  @author: Jenson Bruins
 */
#include <stdio.h>
#include <SDL2/SDL.h>
#include "globals.c"
#include "configurations.c"
#include "field.c"
#include "plants.c"
#include "zombies.c"
#include "waves.c"


void process_input();
void proper_shutdown(void);

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    unsigned int window_flags = 0;
    unsigned int renderer_flags = SDL_RENDERER_ACCELERATED;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    window = SDL_CreateWindow("PlantsVsZombies", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
                              window_flags);
    if (window == NULL)
    {
        printf("Failed to create window -- Error: %s\n",
               SDL_GetError());
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, renderer_flags);
    if (renderer == NULL) // error handling:
    {
        printf("Failed to create renderer -- Error: %s\n",
               SDL_GetError());
        exit(1);
    }

    while (1)
    {
        // Refresh the backbuffer to its original state:
        // RGB (39, 174, 96) should be a green grass color
        SDL_SetRenderDrawColor(renderer, BACKGROUND_COLOR);
        SDL_RenderClear(renderer);
        // Process selected inputs and pay close attention to moving
        // our freshly spawned cow:
        process_input();

        // Render redrawn scene to front buffer, showing it in the
        // actual window:
        SDL_RenderPresent(renderer);
        // Remember ~ 60 FPS of smooth Greta movements - PC Master Race!
        SDL_Delay(16);
    }

    return 0;
}

void process_input()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                proper_shutdown();
                exit(0);
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode)
                {
                    case SDL_SCANCODE_ESCAPE:
                        proper_shutdown();
                        exit(0);
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
}

void proper_shutdown(void)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}