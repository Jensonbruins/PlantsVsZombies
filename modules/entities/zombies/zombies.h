//
// Created by jenson on 12-10-20.
//

#ifndef PLANTSVSZOMBIES_ZOMBIES_H
#define PLANTSVSZOMBIES_ZOMBIES_H
#include "../../../includes/zombieBlueprints.h"
#include "../../filesystem/filesystem.h"
extern void init_zombies(SDL_Renderer *renderer, zombie *object, int lane, int x, int zombie);
extern void init_debug_zombie(SDL_Renderer *renderer, zombie *zombie);
extern void move_zombie(zombie *zombie);
#endif //PLANTSVSZOMBIES_ZOMBIES_H
