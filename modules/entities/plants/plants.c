//
// Created by jenson on 12-10-20.
//

#include "plants.h"

extern void init_sun_hud(SDL_Renderer *renderer, sunGui *sunGuiObject) {
    sunGuiObject->delayCounter = 0;
    sunGuiObject->amount = 1000;
    sunGuiObject->counter = 0;
    texture_initializer(renderer, "gfx/hud/sun/", "sun_", 2, (SDL_Texture * *) & sunGuiObject->texture);
}