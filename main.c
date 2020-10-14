#include "includes/zombieBlueprints.h"
#include "includes/plantBlueprints.h"
#include "modules/modules.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

static void init_sdl();

int main(int argc, char *argv[]) {
    (void) argc;
    (void) argv;

    init_sdl();

    sunGui sunGuiObject;
    sunGuiObject.delayCounter = 0;
    sunGuiObject.amount = 0;
    sunGuiObject.counter = 0;
    texture_initializer(renderer, "gfx/hud/sun/", "sun_", 2, (SDL_Texture * *) & sunGuiObject.texture);

    zombie test;
    init_zombie(renderer, &test);

    SDL_Texture *backgroundTexture = texture_loader(renderer, "gfx/background/background.png");

    int fps = 60;
    unsigned int firstFrame;
    unsigned int frameTime;
    while (1) {
        firstFrame = SDL_GetTicks();                                    // Frame cap logic
        process_input(window, renderer);                                // Process key input and mouse input
        SDL_SetRenderDrawColor(renderer, 120, 144, 156, 255);           // Background color
        SDL_RenderClear(renderer);                                      // Remove all from renderer

        draw_background(renderer, backgroundTexture);                   // Set background
        draw_sun_gui(renderer, &sunGuiObject);
        draw_zombie(renderer, &test);
        move_zombie(&test);

        SDL_RenderPresent(renderer);                                    // Create the big picture
        frameTime = SDL_GetTicks() - firstFrame;                        // Frame cap logic
        if (1000 / (unsigned int) fps > frameTime) {                    // Frame cap logic
            SDL_Delay(1000 / (unsigned int) fps - frameTime);           // Frame cap logic
        }
    }
}

static void init_sdl() {
    unsigned int window_flags = 0;
    unsigned int renderer_flags = SDL_RENDERER_ACCELERATED;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }
    window = SDL_CreateWindow("PlantsVsZombies", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                              SCREEN_HEIGHT, window_flags);
    if (window == NULL) {
        printf("Failed to create window -- Error: %s\n", SDL_GetError());
        exit(1);
    }
    renderer = SDL_CreateRenderer(window, -1, renderer_flags);
    if (renderer == NULL) {
        printf("Failed to create renderer -- Error: %s\n", SDL_GetError());
        exit(1);
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
        printf("Failed to create mixer -- Error: %s\n", SDL_GetError());
        exit(1);
    }

    IMG_Init(IMG_INIT_PNG);
}
