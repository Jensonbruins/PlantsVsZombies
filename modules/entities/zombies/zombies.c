//
// Created by jenson on 12-10-20.
//

#include "zombies.h"
static void init_standard_zombie(SDL_Renderer *renderer, zombie *zombie, int lane, int x);
static void init_cone_zombie(SDL_Renderer *renderer, zombie *zombie, int lane, int x);

extern void init_zombies(SDL_Renderer *renderer, zombie *object, int lane, int x, int zombie) {
    switch (zombie) {
        case(1):
            init_standard_zombie(renderer, object, lane, x);
            break;
        case(2):
            init_cone_zombie(renderer, object, lane, x);
            break;
    }
}

static void init_standard_zombie(SDL_Renderer *renderer, zombie *zombie, int lane, int x) {
    zombie->x = x;
    zombie->health = 5;
    zombie->lane = lane;
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
    texture_initializer(renderer, "gfx/zombie/default/", "walk_", zombie->amountWalkTexture,
                        (SDL_Texture * *) & zombie->textureWalk);
    texture_initializer(renderer, "gfx/zombie/default/", "attack_", zombie->amountAttackTexture,
                        (SDL_Texture * *) & zombie->textureAttack);
}

static void init_cone_zombie(SDL_Renderer *renderer, zombie *zombie, int lane, int x) {
    zombie->x = x;
    zombie->health = 10;
    zombie->lane = lane;
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
    texture_initializer(renderer, "gfx/zombie/cone/", "walk_", zombie->amountWalkTexture,
                        (SDL_Texture * *) & zombie->textureWalk);
    texture_initializer(renderer, "gfx/zombie/cone/", "attack_", zombie->amountAttackTexture,
                        (SDL_Texture * *) & zombie->textureAttack);
    printf("%d\n", zombie->lane);

}

extern void init_debug_zombie(SDL_Renderer *renderer, zombie *zombie) {
    zombie->x = 1400;
    zombie->health = 50;
    zombie->lane = 0;
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
    texture_initializer(renderer, "gfx/zombie/cone/", "walk_", zombie->amountWalkTexture,
                        (SDL_Texture * *) & zombie->textureWalk);
    texture_initializer(renderer, "gfx/zombie/cone/", "attack_", zombie->amountAttackTexture,
                        (SDL_Texture * *) & zombie->textureAttack);

}

extern void move_zombie(zombie *zombie) {
    if (zombie->delayCounter >= 4) {
        if (zombie->x >= 250) {
            zombie->x = zombie->x - 2;
        }
    }
}