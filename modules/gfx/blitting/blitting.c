//
// Created by jenson on 12-10-20.
//

#include "blitting.h"

static void blit(SDL_Renderer *renderer, SDL_Texture *txtr, int x, int y, int center);
static void blit_angled(SDL_Renderer *renderer, SDL_Texture *txtr, int x, int y, float angle);

static void blit(SDL_Renderer *renderer, SDL_Texture *txtr, int x, int y, int center) {
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(txtr, NULL, NULL, &dest.w, &dest.h);
    if (center)
    {
        dest.x -= dest.w / 2;
        dest.y -= dest.h / 2;
    }
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
    blit(renderer, backgroundTexture, 0, 0, 0);
}