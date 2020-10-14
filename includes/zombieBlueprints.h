//
// Created by jenson on 14-10-20.
//

#ifndef PLANTSVSZOMBIES_ZOMBIEBLUEPRINTS_H
#define PLANTSVSZOMBIES_ZOMBIEBLUEPRINTS_H
#include "entityBlueprints.h"
#include "sdl.h"
typedef struct _zombie_ {
    entity components;
    int state;
    int slowDownCounter;
    int walkCounter;
    SDL_Texture *textureWalk[10];
    int attackCounter;
    SDL_Texture *textureAttack[9];
    int dieCounter;
    SDL_Texture *textureDie[12];
} zombie;
#endif //PLANTSVSZOMBIES_ZOMBIEBLUEPRINTS_H
