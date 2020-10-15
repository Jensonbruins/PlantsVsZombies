//
// Created by jenson on 12-10-20.
//

#include "zombies.h"

extern void init_zombie(SDL_Renderer *renderer, zombie *zombie) {
    zombie->x = 1400;
    zombie->y = 50;
    zombie->health = 50;
    zombie->state = 0;
    // Counters to keep track of everything
    zombie->delayCounter = 0;
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
    if (zombie->delayCounter >= 4) {
        if (zombie->x >= 250) {
            zombie->x = zombie->x - 2;
        }
    }
}