//
// Created by jenson on 12-10-20.
//

#ifndef PLANTSVSZOMBIES_PLANTS_H
#define PLANTSVSZOMBIES_PLANTS_H

#include "../../../includes/plantBlueprints.h"
#include "../../filesystem/filesystem.h"

extern void init_plant(SDL_Renderer *renderer, plant *object, int plant);

extern void plant_check_state(SDL_Renderer *renderer, plant plantObjects[45], lane laneObjects[5], projectile projectileObjects[50], sun sunObjects[20]);

extern void move_projectile(projectile object[50]);

extern void init_top_bar(SDL_Renderer *renderer, topBar *object);

extern void init_side_bar(SDL_Renderer *renderer, sideBar *object);

#endif //PLANTSVSZOMBIES_PLANTS_H
