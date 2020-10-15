//
// Created by jenson on 14-10-20.
//

#ifndef PLANTSVSZOMBIES_PLANTBLUEPRINTS_H
#define PLANTSVSZOMBIES_PLANTBLUEPRINTS_H
#include "entityBlueprints.h"
#include "sdl.h"
typedef struct _plant_ {
    entity components;
    int state;
    int delayCounter;
    // Max amount of frames (this if for blitting multiple types of zombies at a time)
    int amountIdleTexture;
    int amountAttackTexture;
    int amountDieTexture;
    // Keeping track of animation
    int idleCounter;
    int attackCounter;
    int dieCounter;
    // Storing the animation preserve 30 cuz thats the max animations of the biggest object ;)
    SDL_Texture *textureIdle[30];
    SDL_Texture *textureAttack[30];
    SDL_Texture *textureDie[30];
} plant;

typedef struct _sun_ {
    entity components;
    int counter;
    SDL_Texture *texture[2];
} sun;

typedef struct _sunGui_ {
    int amount;
    int delayCounter;
    int counter;
    SDL_Texture *texture[2];
} sunGui;
#endif //PLANTSVSZOMBIES_PLANTBLUEPRINTS_H
