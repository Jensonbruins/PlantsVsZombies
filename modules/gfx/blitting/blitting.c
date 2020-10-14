//
// Created by jenson on 12-10-20.
//

#include "blitting.h"

static void blit(SDL_Renderer *renderer, SDL_Texture *txtr, int x, int y);
//static void blit_angled(SDL_Renderer *renderer, SDL_Texture *txtr, int x, int y, float angle);

static void blit(SDL_Renderer *renderer, SDL_Texture *txtr, int x, int y) {
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(txtr, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(renderer, txtr, NULL, &dest);
}

//static void blit_angled(SDL_Renderer *renderer, SDL_Texture *txtr, int x, int y, float angle) {
//    SDL_Rect dest;
//    dest.x = x;
//    dest.y = y;
//    SDL_QueryTexture(txtr, NULL, NULL, &dest.w, &dest.h);
//    dest.x -= (dest.w / 2);
//    dest.y -= (dest.h / 2);
//    SDL_RenderCopyEx(renderer, txtr, NULL, &dest, angle, NULL, SDL_FLIP_NONE);
//}


extern void draw_background(SDL_Renderer *renderer, SDL_Texture *backgroundTexture) {
    blit(renderer, backgroundTexture, 0, 0);
}

extern void draw_zombie(SDL_Renderer *renderer, zombie *zombie) {
    if (zombie->components.health > 0) {
        if (zombie->state == 0) {
            blit(renderer, zombie->textureWalk[zombie->walkCounter], zombie->components.x, zombie->components.y);

            zombie->slowDownCounter++;

            if (zombie->slowDownCounter >= 5) {
                zombie->walkCounter++;
                zombie->slowDownCounter = 0;
            }

            if (zombie->walkCounter >= zombie->amountWalkTexture) {
                zombie->walkCounter = 0;
            }
        }
//        if (zombie->state == 1) {
//            blit(renderer, zombie->textureAttack[zombie->attackCounter], zombie->components.x, zombie->components.y);
//
//            zombie->slowDownCounter++;
//
//            if (zombie->slowDownCounter >= 5) {
//                zombie->attackCounter++;
//                zombie->slowDownCounter = 0;
//            }
//
//            if (zombie->attackCounter >= zombie->amountAttackTexture) {
//                zombie->attackCounter = 0;
//            }
//        }
//        if (zombie->state == 2) {
//
//        }
    }
}

extern void draw_sun_gui(SDL_Renderer *renderer, sunGui *object) {

    object->delayCounter++;
    if (object->delayCounter >= 10) {
        if (object->counter == 0) {
            object->counter = 1;
        } else {
            object->counter = 0;
        }
        object->delayCounter = 0;
    }

    blit(renderer, object->texture[object->counter], 400, 5);

}