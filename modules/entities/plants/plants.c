//
// Created by jenson on 12-10-20.
//

#include "plants.h"

extern void init_plant(SDL_Renderer *renderer, plant *plant) {
    plant->health = 4;
    plant->state = 0;
    // Counters to keep track of everything
    plant->delayCounter = 0;
    plant->idleCounter = 0;
    plant->attackCounter = 0;
    plant->dieCounter = 0;
    // Die texture
    plant->amountIdleTexture = 13;
    plant->amountAttackTexture = 0;
    plant->amountDieTexture = 0;
    texture_initializer(renderer, "gfx/plant/peashooter/", "idle_", plant->amountIdleTexture,
                        (SDL_Texture * *) & plant->textureIdle);
}

extern void init_sun_hud(SDL_Renderer *renderer, sunGui *sunGuiObject) {
    sunGuiObject->delayCounter = 0;
    sunGuiObject->amount = 1000;
    sunGuiObject->counter = 0;
    texture_initializer(renderer, "gfx/hud/sun/", "sun_", 2, (SDL_Texture * *) & sunGuiObject->texture);
}