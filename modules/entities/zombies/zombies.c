//
// Created by jenson on 12-10-20.
//

#include "zombies.h"

extern void init_zombie(SDL_Renderer *renderer, zombie *zombie) {
    zombie->components.x = 1400;
    zombie->components.y = 50;
    zombie->components.health = 50;
    zombie->components.priority = 0;
    zombie->state = 0;
    // Counters to keep track of everything
    zombie->slowDownCounter = 0;
    zombie->walkCounter = 0;
    zombie->attackCounter = 0;
    zombie->dieCounter = 0;
    // Die texture
    zombie->amountWalkTexture = 20;
    zombie->amountAttackTexture = 11;
    zombie->amountDieTexture = 0;
    texture_initializer(renderer, "gfx/zombie/male1/", "walk_", zombie->amountWalkTexture,
                        (SDL_Texture * *) & zombie->textureWalk);
    texture_initializer(renderer, "gfx/zombie/male1/", "attack_", zombie->amountAttackTexture,
                        (SDL_Texture * *) & zombie->textureAttack);

}

extern void move_zombie(zombie *zombie) {
    if (zombie->slowDownCounter >= 4) {
        if (zombie->components.x >= 250) {
            zombie->components.x = zombie->components.x - 2;
        }
    }
}