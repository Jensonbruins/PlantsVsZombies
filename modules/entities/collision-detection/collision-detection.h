//
// Created by jenson on 12-10-20.
//

#ifndef PLANTSVSZOMBIES_COLLISION_DETECTION_H
#define PLANTSVSZOMBIES_COLLISION_DETECTION_H

#include "../../../includes/sdl.h"
#include "../../../includes/plantBlueprints.h"
#include "../../../includes/zombieBlueprints.h"

extern void zombie_check_collision(zombie zombieObject[50], int amount, lane laneArray[5], plant plantArray[45]);

extern void zombie_check_in_range(zombie zombieObject[50], int amount, lane laneArray[5], plant plantArray[45]);

extern void projectile_check_hit(zombie zombieObjects[50], projectile projectileObjects[50]);

#endif //PLANTSVSZOMBIES_COLLISION_DETECTION_H
