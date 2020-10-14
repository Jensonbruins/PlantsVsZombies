//
// Created by jenson on 12-10-20.
//

#include "blitting.h"

static void blit(SDL_Renderer *renderer, SDL_Texture *txtr, int x, int y);
static void blit_angled(SDL_Renderer *renderer, SDL_Texture *txtr, int x, int y, float angle);

static void blit(SDL_Renderer *renderer, SDL_Texture *txtr, int x, int y) {
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(txtr, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(renderer, txtr, NULL, &dest);
}

static void blit_angled(SDL_Renderer *renderer, SDL_Texture *txtr, int x, int y, float angle) {
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(txtr, NULL, NULL, &dest.w, &dest.h);
    dest.x -= (dest.w / 2);
    dest.y -= (dest.h / 2);
    SDL_RenderCopyEx(renderer, txtr, NULL, &dest, angle, NULL, SDL_FLIP_NONE);
}


extern void draw_background(SDL_Renderer *renderer, SDL_Texture *backgroundTexture) {
    blit(renderer, backgroundTexture, 0, 0);
}

extern void draw_zombie(SDL_Renderer *renderer, zombie *zombie) {
    if (zombie->components.health > 0) {
        if (zombie->state == 0) {

            blit(renderer, zombie->textureWalk[0], zombie->components.x, zombie->components.y);
        }
    }
}