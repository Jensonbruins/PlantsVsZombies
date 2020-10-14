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
    zombie->attackCounter = 0;
    zombie->dieCounter = 0;
    // Die texture
    zombie->amountWalkTexture = 20;
    zombie->amountAttackTexture = 11;
    zombie->amountDieTexture = 0;
}

extern void move_zombie(zombie *zombie) {
    if (zombie->slowDownCounter >= 4) {
        if (zombie->components.x > 250) {
            zombie->components.x = zombie->components.x - 2;
        } else {
            zombie->state = 1;
        }
    }
}