//
// Created by jenson on 12-10-20.
//

#include "collision-detection.h"

static void zombie_collision_helper(zombie *zombieObject, lane *laneObject, plant plantArray[45]);

static void in_range_helper(zombie *zombieObject, lane *laneObject, plant plantArray[45]);

extern void zombie_check_collision(zombie zombieObject[40], int amount, lane laneArray[5], plant plantArray[45]) {
    for (int k = 0; k < amount; k++) {
        switch (zombieObject[k].lane) {
            case 0:
                zombie_collision_helper(&zombieObject[k], &laneArray[0], plantArray);
                break;
            case 1:
                zombie_collision_helper(&zombieObject[k], &laneArray[1], plantArray);
                break;
            case 2:
                zombie_collision_helper(&zombieObject[k], &laneArray[2], plantArray);
                break;
            case 3:
                zombie_collision_helper(&zombieObject[k], &laneArray[3], plantArray);
                break;
            case 4:
                zombie_collision_helper(&zombieObject[k], &laneArray[4], plantArray);
                break;
            default:
                continue;
        }
    }
}

static void zombie_collision_helper(zombie *zombieObject, lane *laneObject, plant plantArray[45]) {
    for (int k = 8; k >= 0; k--) {
        if (!(laneObject->blockArray[k].plantId > 45)) {
            if (plantArray[laneObject->blockArray[k].plantId].health > 0) {
                if (laneObject->blockArray[k].x >= (zombieObject->x + 50) &&
                    (zombieObject->x + 80) >= laneObject->blockArray[k].x) {
                    zombieObject->state = 1;
                    if ((unsigned int) (zombieObject->lastHit + 3000) <= SDL_GetTicks()) {
                        int oldHealth = plantArray[laneObject->blockArray[k].plantId].health;
                        int newHealth = oldHealth - zombieObject->damage;
                        if (newHealth <= 0) {
                            plantArray[laneObject->blockArray[k].plantId].health = 0;
                        } else {
                            plantArray[laneObject->blockArray[k].plantId].health = newHealth;
                        }
                        zombieObject->lastHit = SDL_GetTicks();
                    }
                    break;
                } else {
                    zombieObject->state = 0;
                }
            } else {
                zombieObject->state = 0;
            }
        }
    }
}

extern void zombie_check_in_range(zombie zombieObject[40], int amount, lane laneArray[5], plant plantArray[45]) {
    for (int k = 0; k < amount; k++) {
        switch (zombieObject[k].lane) {
            case 0:
                in_range_helper(&zombieObject[k], &laneArray[0], plantArray);
                break;
            case 1:
                in_range_helper(&zombieObject[k], &laneArray[1], plantArray);
                break;
            case 2:
                in_range_helper(&zombieObject[k], &laneArray[2], plantArray);
                break;
            case 3:
                in_range_helper(&zombieObject[k], &laneArray[3], plantArray);
                break;
            case 4:
                in_range_helper(&zombieObject[k], &laneArray[4], plantArray);
                break;
            default:
                continue;
        }
    }
}

static void in_range_helper(zombie *zombieObject, lane *laneObject, plant plantArray[45]) {
    for (int k = 0; k < 9; k++) {
        if (!(laneObject->blockArray[k].plantId > 45)) {
            if (plantArray[laneObject->blockArray[k].plantId].health > 0 && zombieObject->health > 0) {
                if (laneObject->blockArray[k].x < zombieObject->x && zombieObject->x < 1500) {
                    plantArray[laneObject->blockArray[k].plantId].state = 1;
                } else {
                    plantArray[laneObject->blockArray[k].plantId].state = 0;
                }
            } else {
                plantArray[laneObject->blockArray[k].plantId].state = 0;
            }
        }
    }
}

extern void projectile_check_hit(zombie zombieObjects[40], projectile projectileObjects[50]) {
    for (int k = 0; k < 50; k++) {
        if (projectileObjects[k].alive > 0) {
            for (int n = 0; n < 40; n++) {
                if (zombieObjects[n].health > 0) {
                    if (zombieObjects[n].lane == projectileObjects[k].lane) {
                        if ((zombieObjects[n].x + 100) <= projectileObjects[k].x) {
                            projectileObjects[k].alive = 0;
                            if (zombieObjects[n].health <= 0) {
                                zombieObjects[n].health = 0;
                            } else {
                                zombieObjects[n].health = zombieObjects[n].health - projectileObjects[k].damage;
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}