//
// Created by jenson on 14-10-20.
//

#ifndef PLANTSVSZOMBIES_PLANTBLUEPRINTS_H
#define PLANTSVSZOMBIES_PLANTBLUEPRINTS_H

#include "sdl.h"

typedef struct _gridBlock_ {
    int x;
    int plantId;
} gridBlock;

typedef struct _lane_ {
    int y;
    gridBlock blockArray[9];
} lane;

typedef struct _plant_ {
    int health;
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
    // Damage
    unsigned int lastShot;
    int type;
    // Storing the animation preserve 30 cuz thats the max animations of the biggest object ;)
    SDL_Texture *textureIdle[30];
    SDL_Texture *textureAttack[30];
    SDL_Texture *textureDie[30];
} plant;

typedef struct _projectile_ {
    int alive;
    int damage;
    int y;
    int x;
    int lane;
    SDL_Texture *texture;
} projectile;

typedef struct _sun_ {
    int x;
    int y;
    int alive;
    int worth;
    int counter;
    int delayCounter;
    unsigned int spawnTimer;
    SDL_Texture *texture[2];
} sun;

typedef struct _topBar_ {
    int amount;
    int delayCounter;
    int counter;
    SDL_Texture *texture[2];
} topBar;

typedef struct _sideBar_ {
    int selection;
    int amountTextures;
    SDL_Texture *texture[10];
} sideBar;
#endif //PLANTSVSZOMBIES_PLANTBLUEPRINTS_H
