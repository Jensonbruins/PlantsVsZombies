//
// Created by jenson on 12-10-20.
//

#ifndef PLANTSVSZOMBIES_BLITTING_H
#define PLANTSVSZOMBIES_BLITTING_H
#include "../../../includes/zombieBlueprints.h"
#include "../../../includes/plantBlueprints.h"
extern void draw_background(SDL_Renderer *renderer, SDL_Texture *txtr);
extern void draw_zombie(SDL_Renderer *renderer, zombie *zombie);
extern void draw_plant(SDL_Renderer *renderer, plant *object);
extern void draw_sun_gui(SDL_Renderer *renderer, sunGui *object, TTF_Font *font);
#endif //PLANTSVSZOMBIES_BLITTING_H
