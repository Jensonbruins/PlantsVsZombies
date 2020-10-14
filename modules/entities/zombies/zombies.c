//
// Created by jenson on 12-10-20.
//

#include "zombies.h"

extern void init_zombie(zombie *zombie) {
    zombie->components.x = 1400;
    zombie->components.y = 50;
    zombie->components.health = 50;
    zombie->components.priority = 0;
    zombie->state = 0;
    zombie->walkCounter = 0;
}