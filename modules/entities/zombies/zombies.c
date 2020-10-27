//
// Created by jenson on 12-10-20.
//

#include "zombies.h"

static void init_default_zombie(SDL_Renderer *renderer, zombie *zombie, int lane, int x);

static void init_cone_zombie(SDL_Renderer *renderer, zombie *zombie, int lane, int x);

static void init_flag_zombie(SDL_Renderer *renderer, zombie *zombie, int lane, int x);

static void init_bucket_zombie(SDL_Renderer *renderer, zombie *zombie, int lane, int x);

extern void init_zombies(SDL_Renderer *renderer, zombie objects[50], int array[][3], int amount) {
    for (int k = 0; k < amount; k++) {
        switch (array[k][2]) {
            case (1):
                init_default_zombie(renderer, &objects[k], array[k][0], array[k][1]);
                break;
            case (2):
                init_cone_zombie(renderer, &objects[k], array[k][0], array[k][1]);
                break;
            case (3):
                init_flag_zombie(renderer, &objects[k], array[k][0], array[k][1]);
                break;
            case (4):
                init_bucket_zombie(renderer, &objects[k], array[k][0], array[k][1]);
                break;
        }
    }
}

static void init_default_zombie(SDL_Renderer *renderer, zombie *zombie, int lane, int x) {
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
    zombie->amountWalkTexture = 22;
    zombie->amountAttackTexture = 21;
    zombie->amountDieTexture = 0;

    // Damage
    zombie->damage = 1;
    zombie->lastHit = 0;

    // Textures
    texture_initializer(renderer, "gfx/zombie/default/", "walk_", zombie->amountWalkTexture,
                        (SDL_Texture **) &zombie->textureWalk);
    texture_initializer(renderer, "gfx/zombie/default/", "attack_", zombie->amountAttackTexture,
                        (SDL_Texture **) &zombie->textureAttack);
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

    // Damage
    zombie->damage = 2;
    zombie->lastHit = 0;

    // Textures
    texture_initializer(renderer, "gfx/zombie/cone/", "walk_", zombie->amountWalkTexture,
                        (SDL_Texture **) &zombie->textureWalk);
    texture_initializer(renderer, "gfx/zombie/cone/", "attack_", zombie->amountAttackTexture,
                        (SDL_Texture **) &zombie->textureAttack);
}

static void init_flag_zombie(SDL_Renderer *renderer, zombie *zombie, int lane, int x) {
    zombie->x = x;
    zombie->health = 15;
    zombie->lane = lane;
    zombie->state = 0;

    // Counters to keep track of everything
    zombie->delayCounter = 0;
    zombie->walkCounter = 0;
    zombie->attackCounter = 0;
    zombie->dieCounter = 0;

    // Die texture
    zombie->amountWalkTexture = 12;
    zombie->amountAttackTexture = 11;
    zombie->amountDieTexture = 0;

    // Damage
    zombie->damage = 1;
    zombie->lastHit = 0;

    // Textures
    texture_initializer(renderer, "gfx/zombie/flag/", "walk_", zombie->amountWalkTexture,
                        (SDL_Texture **) &zombie->textureWalk);
    texture_initializer(renderer, "gfx/zombie/flag/", "attack_", zombie->amountAttackTexture,
                        (SDL_Texture **) &zombie->textureAttack);
}

static void init_bucket_zombie(SDL_Renderer *renderer, zombie *zombie, int lane, int x) {
    zombie->x = x;
    zombie->health = 15;
    zombie->lane = lane;
    zombie->state = 0;

    // Counters to keep track of everything
    zombie->delayCounter = 0;
    zombie->walkCounter = 0;
    zombie->attackCounter = 0;
    zombie->dieCounter = 0;

    // Die texture
    zombie->amountWalkTexture = 15;
    zombie->amountAttackTexture = 11;
    zombie->amountDieTexture = 0;

    // Damage
    zombie->damage = 1;
    zombie->lastHit = 0;

    // Textures
    texture_initializer(renderer, "gfx/zombie/bucket/", "walk_", zombie->amountWalkTexture,
                        (SDL_Texture **) &zombie->textureWalk);
    texture_initializer(renderer, "gfx/zombie/bucket/", "attack_", zombie->amountAttackTexture,
                        (SDL_Texture **) &zombie->textureAttack);
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
                        (SDL_Texture **) &zombie->textureWalk);
    texture_initializer(renderer, "gfx/zombie/cone/", "attack_", zombie->amountAttackTexture,
                        (SDL_Texture **) &zombie->textureAttack);

}

extern void move_zombie(zombie objects[40], int amount) {
    for (int k = 0; k < amount; k++) {
        if (objects[k].health > 0) {
            if (objects[k].delayCounter >= 4) {
                if (objects[k].state == 0) {
                    objects[k].x = objects[k].x - 2;
                }
            }
        }
    }
}