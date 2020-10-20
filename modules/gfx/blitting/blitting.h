//
// Created by jenson on 12-10-20.
//

#ifndef PLANTSVSZOMBIES_BLITTING_H
#define PLANTSVSZOMBIES_BLITTING_H
#include "../../../includes/zombieBlueprints.h"
#include "../../../includes/plantBlueprints.h"
extern void draw_background(SDL_Renderer *renderer, SDL_Texture *txtr);
extern void draw_zombie(SDL_Renderer *renderer, zombie objects[40], int amount);
extern void draw_plant(SDL_Renderer *renderer, plant *object, int x, int y);
extern void draw_plants(SDL_Renderer *renderer, lane laneArray[5], plant objects[45]);
extern void draw_topbar(SDL_Renderer *renderer, topBar *object, TTF_Font *font);
extern void draw_sidebar(SDL_Renderer *renderer, sideBar *object, topBar *topBarObject);
#endif //PLANTSVSZOMBIES_BLITTING_H
