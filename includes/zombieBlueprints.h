//
// Created by jenson on 14-10-20.
//

#ifndef PLANTSVSZOMBIES_ZOMBIEBLUEPRINTS_H
#define PLANTSVSZOMBIES_ZOMBIEBLUEPRINTS_H
#include "entityBlueprints.h"
typedef struct _zombie_ {
    entity components;
    int priority;
    SDL_Texture *textureWalk[];
    SDL_Texture *textureAttack[];
    SDL_Texture *textureDie[];
} zombie;
#endif //PLANTSVSZOMBIES_ZOMBIEBLUEPRINTS_H
