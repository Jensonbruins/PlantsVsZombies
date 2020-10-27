//
// Created by jenson on 12-10-20.
//

#ifndef PLANTSVSZOMBIES_FILESYSTEM_H
#define PLANTSVSZOMBIES_FILESYSTEM_H

#include "../../includes/sdl.h"

extern void texture_initializer(SDL_Renderer *renderer, char *path, char *filePrefix, int amountTextures, SDL_Texture *textureSet[]);

extern SDL_Texture *texture_loader(SDL_Renderer *renderer, char *filename);

#endif //PLANTSVSZOMBIES_FILESYSTEM_H
