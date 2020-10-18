//
// Created by jenson on 12-10-20.
//

#ifndef PLANTSVSZOMBIES_INPUT_H
#define PLANTSVSZOMBIES_INPUT_H
#include "../../includes/sdl.h"
#include "../../includes/plantBlueprints.h"
#include "../entities/plants/plants.h"
extern void process_input(SDL_Window *window, SDL_Renderer *renderer, TTF_Font *font, lane laneArray[5], plant plantArray[45], sideBar *sideBarObject, topBar *topBarObject);
#endif //PLANTSVSZOMBIES_INPUT_H
