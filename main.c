/*
 *  @since: v1.0.0
 *  @author: Jenson Bruins
 */
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include "globals.c"

void setup_screen();
void process_input();
void proper_shutdown(void);


#include "render.c"
#include "timers.c"

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    setup_screen();

    IMG_Init(IMG_INIT_PNG);
    SDL_Texture *txtr_background;
    txtr_background = load_texture("../gfx/background.png");


    while (1)
    {
        // Refresh the backbuffer to its original state:
        // RGB (39, 174, 96) should be a green grass color
        SDL_SetRenderDrawColor(renderer, BACKGROUND_COLOR);
        SDL_RenderClear(renderer);
        // Process selected inputs and pay close attention to moving
        // our freshly spawned cow:
        process_input();

        blit(txtr_background, 0, 0, 0);

        // actual window:
        SDL_RenderPresent(renderer);
        // Remember ~ 60 FPS - PC Master Race!
        SDL_Delay(16);
    }

    return 0;
}

void setup_screen() {
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
        printf("FaUint32iled to create renderer -- Error: %s\n",
               SDL_GetError());
        exit(1);
    }
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
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode)
                {
                    case SDL_SCANCODE_ESCAPE:
                        proper_shutdown();
                        exit(0);
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
