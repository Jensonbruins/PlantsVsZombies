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

    sunGui sunHudObject;
    init_sun_hud(renderer, &sunHudObject);

    zombie zombieObject;
    init_zombie(renderer, &zombieObject);

    plant plantObject;
    init_plant(renderer, &plantObject);

    SDL_Texture *backgroundTexture = texture_loader(renderer, "gfx/background/background.png");
    TTF_Font *font = TTF_OpenFont("gfx/hud/sun/arial.ttf", 28);

    int fps = 60;
    unsigned int firstFrame;
    unsigned int frameTime;
    while (1) {
        firstFrame = SDL_GetTicks();                                    // Frame cap logic
        process_input(window, renderer, font);                          // Process key input and mouse input
        SDL_RenderClear(renderer);                                      // Remove all from renderer

        draw_background(renderer, backgroundTexture);                   // Set background
        draw_sun_gui(renderer, &sunHudObject, font);
        draw_zombie(renderer, &zombieObject);
        move_zombie(&zombieObject);

        draw_plant(renderer, &plantObject);

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
    if(TTF_Init() < 0) {
        printf("Failed to initialize SDL_ttf: %s\n", SDL_GetError());
        exit(1);
    }
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("Failed to initialize SDL_image: %s\n", SDL_GetError());
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
}
