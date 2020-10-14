//
// Created by jenson on 14-10-20.
//

#ifndef PLANTSVSZOMBIES_PLANTBLUEPRINTS_H
#define PLANTSVSZOMBIES_PLANTBLUEPRINTS_H
#include "entityBlueprints.h"
#include "sdl.h"
typedef struct _sun_ {
    entity components;
    int counter;
    SDL_Texture *texture[2];
} sun;


#endif //PLANTSVSZOMBIES_PLANTBLUEPRINTS_H
