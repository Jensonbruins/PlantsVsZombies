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
    // Max amount of frames (this if for blitting multiple types of zombies at a time)
    int amountWalkTexture;
    int amountAttackTexture;
    int amountDieTexture;
    // Keeping track of animation
    int walkCounter;
    int attackCounter;
    int dieCounter;
    // Storing the animation preserve 30 cuz thats the max animations of the biggest object ;)
    SDL_Texture *textureWalk[30];
    SDL_Texture *textureAttack[30];
    SDL_Texture *textureDie[30];
} zombie;
#endif //PLANTSVSZOMBIES_ZOMBIEBLUEPRINTS_H
