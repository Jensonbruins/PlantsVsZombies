//
// Created by jenson on 12-10-20.
//

#include "filesystem.h"

extern void texture_initializer(SDL_Renderer *renderer, char *path, char *filePrefix, int amountTextures, SDL_Texture *textureSet[]) {
    for(int temp = 0; temp < amountTextures; temp++) {
        char filename[50];

        sprintf(filename, "%s%s%d.png", path, filePrefix, (temp + 1));
        printf("Loading texture %s\n", filename);

        textureSet[temp] = texture_loader(renderer, filename);
    }
}

extern SDL_Texture *texture_loader(SDL_Renderer *renderer, char *filename) {
    SDL_Texture *txtr;
    txtr = IMG_LoadTexture(renderer, filename);
    return txtr;
}
