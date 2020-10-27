//
// Created by jenson on 12-10-20.
//

#include "plants.h"

static void init_peashooter(SDL_Renderer *renderer, plant *object);

static void init_sunflower(SDL_Renderer *renderer, plant *object);

static void init_walnut(SDL_Renderer *renderer, plant *object);

static void init_peashooter_projectile(SDL_Renderer *renderer, int lane, int x, int y, projectile *object);

static void init_sunflower_projectile(SDL_Renderer *renderer, int x, int y, sun *object);

extern void init_plant(SDL_Renderer *renderer, plant *object, int plant) {

    switch (plant) {
        case 1:
            init_peashooter(renderer, object);
            break;
        case 2:
            init_sunflower(renderer, object);
            break;
        case 3:
            init_walnut(renderer, object);
            break;
        default:
            break;
    }
}

extern void plant_check_state(SDL_Renderer *renderer, plant plantObjects[45], lane laneObjects[5], projectile projectileObjects[50], sun sunObjects[20]) {
    for (int k = 0; k < 45; k++) {
        if (plantObjects[k].health > 0) {
            if (plantObjects[k].state == 1) {
                int projectileNumber;
                int sunObjectNumber = 21;

                for (int n = 0; n < 50; n++) {
                    if (projectileObjects[n].x > 1600) {
                        projectileObjects[n].alive = 0;
                    }

                    if (projectileObjects[n].alive != 1) {
                        projectileNumber = n;
                        break;
                    }
                }
                for (int n = 0; n < 20; n++) {
                    if ((unsigned int) (sunObjects[n].spawnTimer + 7500) <= SDL_GetTicks()) {
                        sunObjects[n].alive = 0;
                    }

                    if (sunObjects[n].alive != 1) {
                        sunObjectNumber = n;
                        break;
                    }
                }

                for (int row = 0; row < 5; row++) {
                    for (int t = 0; t < 9; t++) {
                        if (laneObjects[row].blockArray[t].plantId == k) {
                            switch (plantObjects[k].type) {
                                case (1):
                                    if ((unsigned int) (plantObjects[k].lastShot + 3000) <= SDL_GetTicks()) {
                                        init_peashooter_projectile(renderer, row, laneObjects[row].blockArray[t].x, laneObjects[row].y, &projectileObjects[projectileNumber]);
                                        plantObjects[k].lastShot = SDL_GetTicks();
                                    }
                                    break;
                                case (2):
                                    if ((unsigned int) (plantObjects[k].lastShot + 15000) <= SDL_GetTicks()) {
                                        if (sunObjectNumber < 21) {
                                            init_sunflower_projectile(renderer, laneObjects[row].blockArray[t].x,
                                                                      laneObjects[row].y,
                                                                      &sunObjects[sunObjectNumber]);
                                        }
                                        plantObjects[k].lastShot = SDL_GetTicks();
                                    }
                                    break;
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}

extern void move_projectile(projectile object[50]) {
    for (int k = 0; k < 50; k++) {
        if (object[k].alive > 0) {
            object[k].x = object[k].x + 5;
        }
    }
}

static void init_peashooter(SDL_Renderer *renderer, plant *object) {
    object->type = 1;
    object->health = 4;
    object->state = 0;
    // Counters to keep track of everything
    object->delayCounter = 0;
    object->idleCounter = 0;
    object->attackCounter = 0;
    object->dieCounter = 0;
    object->lastShot = SDL_GetTicks();
    object->canShoot = 1;
    // Die texture
    object->amountIdleTexture = 13;
    object->amountAttackTexture = 0;
    object->amountDieTexture = 0;
    texture_initializer(renderer, "gfx/plant/peashooter/", "idle_", object->amountIdleTexture,
                        (SDL_Texture **) &object->textureIdle);
}

static void init_sunflower(SDL_Renderer *renderer, plant *object) {
    object->type = 2;
    object->health = 4;
    object->state = 1;
    // Counters to keep track of everything
    object->delayCounter = 0;
    object->idleCounter = 0;
    object->attackCounter = 0;
    object->dieCounter = 0;
    object->canShoot = 0;
    // Die texture
    object->lastShot = SDL_GetTicks();
    object->amountIdleTexture = 18;
    object->amountAttackTexture = 0;
    object->amountDieTexture = 0;
    texture_initializer(renderer, "gfx/plant/sunflower/", "idle_", object->amountIdleTexture,
                        (SDL_Texture **) &object->textureIdle);
}

static void init_walnut(SDL_Renderer *renderer, plant *object) {
    object->type = 3;
    object->health = 4;
    object->state = 0;
    // Counters to keep track of everything
    object->delayCounter = 0;
    object->idleCounter = 0;
    object->attackCounter = 0;
    object->dieCounter = 0;
    // Die texture
    object->canShoot = 0;
    object->lastShot = SDL_GetTicks();
    object->amountIdleTexture = 16;
    object->amountAttackTexture = 0;
    object->amountDieTexture = 0;
    texture_initializer(renderer, "gfx/plant/walnut/", "idle_", object->amountIdleTexture,
                        (SDL_Texture **) &object->textureIdle);
}

static void init_peashooter_projectile(SDL_Renderer *renderer, int lane, int x, int y, projectile *object) {
    object->alive = 1;
    object->damage = 1;
    object->x = x + 54;
    object->y = y + 10;
    object->lane = lane;
    object->texture = texture_loader(renderer, "gfx/plant/peashooter/projectile.png");
}

static void init_sunflower_projectile(SDL_Renderer *renderer, int x, int y, sun *object) {
    object->alive = 1;
    object->worth = 25;
    object->x = x + 20;
    object->y = y + 40;
    object->counter = 0;
    object->spawnTimer = SDL_GetTicks();
    texture_initializer(renderer, "gfx/hud/sun/", "sun_", 2, (SDL_Texture **) &object->texture);
}

extern void init_top_bar(SDL_Renderer *renderer, topBar *object) {
    object->delayCounter = 0;
    object->amount = 500;
    object->counter = 0;
    texture_initializer(renderer, "gfx/hud/sun/", "sun_", 2, (SDL_Texture **) &object->texture);
}

extern void init_side_bar(SDL_Renderer *renderer, sideBar *object) {
    object->selection = 0;
    object->amountTextures = 3;
    object->texture[0] = texture_loader(renderer, "gfx/hud/sidebar/peashooterseed.png");
    object->texture[1] = texture_loader(renderer, "gfx/hud/sidebar/sunflowerseed.png");
    object->texture[2] = texture_loader(renderer, "gfx/hud/sidebar/walnutseed.png");
}