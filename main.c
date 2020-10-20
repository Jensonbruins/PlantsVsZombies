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

    topBar topBarObject;
    init_top_bar(renderer, &topBarObject);

    sideBar sideBarObject;
    init_side_bar(renderer, &sideBarObject);

    zombie zombieObjects[40];
    int amountOfZombies = 2;
    int zombieArray[40][3] = {
            {0, 1600, 2},
            {1, 1600, 2}
    };
    init_zombies(renderer, (zombie *) &zombieObjects, zombieArray, amountOfZombies);

    plant plantObjects[45];
    projectile projectileObjects[50];

    int noPlant = 50;
    int block1 = 410; int block2 = 540; int block3 = 670; int block4 = 800; int block5 = 920; int block6 = 1050; int block7 = 1170; int block8 = 1300; int block9 = 1430;

    gridBlock blockArray[9] = {
            {block1, noPlant},
            {block2, noPlant},
            {block3, noPlant},
            {block4, noPlant},
            {block5, noPlant},
            {block6, noPlant},
            {block7, noPlant},
            {block8, noPlant},
            {block9, noPlant}
    };

    lane laneArray[5] = {
            { 120 , {{blockArray[0].x, blockArray[0].plantId}, {blockArray[1].x, blockArray[1].plantId}, {blockArray[2].x, blockArray[2].plantId}, {blockArray[3].x, blockArray[3].plantId}, {blockArray[4].x, blockArray[4].plantId}, {blockArray[5].x, blockArray[5].plantId}, {blockArray[6].x, blockArray[6].plantId}, {blockArray[7].x, blockArray[7].plantId}, {blockArray[8].x, blockArray[8].plantId}}},
            { 270 , {{blockArray[0].x, blockArray[0].plantId}, {blockArray[1].x, blockArray[1].plantId}, {blockArray[2].x, blockArray[2].plantId}, {blockArray[3].x, blockArray[3].plantId}, {blockArray[4].x, blockArray[4].plantId}, {blockArray[5].x, blockArray[5].plantId}, {blockArray[6].x, blockArray[6].plantId}, {blockArray[7].x, blockArray[7].plantId}, {blockArray[8].x, blockArray[8].plantId}}},
            { 420 , {{blockArray[0].x, blockArray[0].plantId}, {blockArray[1].x, blockArray[1].plantId}, {blockArray[2].x, blockArray[2].plantId}, {blockArray[3].x, blockArray[3].plantId}, {blockArray[4].x, blockArray[4].plantId}, {blockArray[5].x, blockArray[5].plantId}, {blockArray[6].x, blockArray[6].plantId}, {blockArray[7].x, blockArray[7].plantId}, {blockArray[8].x, blockArray[8].plantId}}},
            { 560 , {{blockArray[0].x, blockArray[0].plantId}, {blockArray[1].x, blockArray[1].plantId}, {blockArray[2].x, blockArray[2].plantId}, {blockArray[3].x, blockArray[3].plantId}, {blockArray[4].x, blockArray[4].plantId}, {blockArray[5].x, blockArray[5].plantId}, {blockArray[6].x, blockArray[6].plantId}, {blockArray[7].x, blockArray[7].plantId}, {blockArray[8].x, blockArray[8].plantId}}},
            { 700 , {{blockArray[0].x, blockArray[0].plantId}, {blockArray[1].x, blockArray[1].plantId}, {blockArray[2].x, blockArray[2].plantId}, {blockArray[3].x, blockArray[3].plantId}, {blockArray[4].x, blockArray[4].plantId}, {blockArray[5].x, blockArray[5].plantId}, {blockArray[6].x, blockArray[6].plantId}, {blockArray[7].x, blockArray[7].plantId}, {blockArray[8].x, blockArray[8].plantId}}}
    };

    SDL_Texture *backgroundTexture = texture_loader(renderer, "gfx/background/background.png");
    TTF_Font *font = TTF_OpenFont("gfx/hud/sun/arial.ttf", 28);

    int fps = 60;
    unsigned int firstFrame;
    unsigned int frameTime;
    while (1) {
        firstFrame = SDL_GetTicks();                                    // Frame cap logic
        process_input(window, renderer, font, (lane*) &laneArray,(plant*) &plantObjects, &sideBarObject, &topBarObject);                          // Process key input and mouse input
        SDL_RenderClear(renderer);                                      // Remove all from renderer

        draw_background(renderer, backgroundTexture);                   // Set background
        draw_topbar(renderer, &topBarObject, font);
        draw_sidebar(renderer, &sideBarObject, &topBarObject);

        draw_projectile(renderer,(projectile *) &projectileObjects);

        draw_plants(renderer,(lane*) &laneArray,(plant*) &plantObjects);

        draw_zombie(renderer, (zombie *) &zombieObjects, amountOfZombies);
        move_zombie((zombie *) &zombieObjects, amountOfZombies);

        zombie_check_collision((zombie *) &zombieObjects, amountOfZombies, (lane *) &laneArray, (plant*) &plantObjects);
        zombie_check_in_range((zombie *) &zombieObjects, amountOfZombies, (lane *) &laneArray, (plant*) &plantObjects);
        plant_check_state(renderer,(plant*) &plantObjects, (lane *) &laneArray, (projectile *) &projectileObjects);

        move_projectile((projectile *) &projectileObjects);

//        projectile_check_hit((zombie *) &zombieObjects, (projectile *) &projectileObjects);

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
