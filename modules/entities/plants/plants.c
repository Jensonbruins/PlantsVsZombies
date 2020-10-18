//
// Created by jenson on 12-10-20.
//

#include "plants.h"

static void init_peashooter(SDL_Renderer *renderer, plant *object);
static void init_sunflower(SDL_Renderer *renderer, plant *object);

extern void init_plant(SDL_Renderer *renderer, plant *object, int plant) {

    switch (plant) {
        case 1:
            init_peashooter(renderer, object);
            break;
        case 2:
            init_sunflower(renderer, object);
        default:
            break;
    }
}

static void init_peashooter(SDL_Renderer *renderer, plant *object) {
    object->health = 4;
    object->state = 0;
    // Counters to keep track of everything
    object->delayCounter = 0;
    object->idleCounter = 0;
    object->attackCounter = 0;
    object->dieCounter = 0;
    // Die texture
    object->amountIdleTexture = 13;
    object->amountAttackTexture = 0;
    object->amountDieTexture = 0;
    texture_initializer(renderer, "gfx/plant/peashooter/", "idle_", object->amountIdleTexture,
                        (SDL_Texture * *) & object->textureIdle);
}

static void init_sunflower(SDL_Renderer *renderer, plant *object) {
    object->health = 4;
    object->state = 0;
    // Counters to keep track of everything
    object->delayCounter = 0;
    object->idleCounter = 0;
    object->attackCounter = 0;
    object->dieCounter = 0;
    // Die texture
    object->amountIdleTexture = 18;
    object->amountAttackTexture = 0;
    object->amountDieTexture = 0;
    texture_initializer(renderer, "gfx/plant/sunflower/", "idle_", object->amountIdleTexture,
                        (SDL_Texture * *) & object->textureIdle);
}

extern void init_top_bar(SDL_Renderer *renderer, topBar *object) {
    object->delayCounter = 0;
    object->amount = 10000;
    object->counter = 0;
    texture_initializer(renderer, "gfx/hud/sun/", "sun_", 2, (SDL_Texture * *) & object->texture);
}

extern void init_side_bar(SDL_Renderer *renderer, sideBar *object) {
    object->selection = 0;
    object->amountTextures = 2;
    object->texture[0] = texture_loader(renderer, "gfx/hud/sidebar/peashooterseed.png");
    object->texture[1] = texture_loader(renderer, "gfx/hud/sidebar/sunflowerseed.png");
}