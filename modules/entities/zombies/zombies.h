//
// Created by jenson on 12-10-20.
//

#ifndef PLANTSVSZOMBIES_ZOMBIES_H
#define PLANTSVSZOMBIES_ZOMBIES_H

#include "../../../includes/zombieBlueprints.h"
#include "../../filesystem/filesystem.h"

extern void init_zombies(SDL_Renderer *renderer, zombie objects[40], int array[][3], int amount);

extern void init_debug_zombie(SDL_Renderer *renderer, zombie *zombie);

extern void move_zombie(zombie objects[40], int amount);

#endif //PLANTSVSZOMBIES_ZOMBIES_H
