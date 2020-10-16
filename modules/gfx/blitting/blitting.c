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

extern void draw_zombie(SDL_Renderer *renderer, zombie *object) {
    if (object->health > 0) {
        if (object->state == 0) {
            blit(renderer, object->textureWalk[object->walkCounter], object->x, object->y);

            object->delayCounter++;

            if (object->delayCounter >= 5) {
                object->walkCounter++;
                object->delayCounter = 0;
            }

            if (object->walkCounter >= object->amountWalkTexture) {
                object->walkCounter = 0;
            }
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

extern void draw_plant(SDL_Renderer *renderer, plant *object, int x, int y) {
    if (object->health > 0) {
        if (object->state == 0) {
            blit(renderer, object->textureIdle[object->idleCounter], x, y);

            object->delayCounter++;

            if (object->delayCounter >= 4) {
                object->idleCounter++;
                object->delayCounter = 0;
            }

            if (object->idleCounter >= object->amountIdleTexture) {
                object->idleCounter = 0;
            }
        }
    }
}

extern void draw_plants(SDL_Renderer *renderer, lane laneArray[5], plant plantArray[45]) {
    for(int row = 0; row <= 4; row++) {
        int y = laneArray[row].y;
//        printf("%d\n", y);
        for (int column = 0; column <= 8; column++) {
            int plantId = laneArray[row].blockArray[column].plantId;
            if (plantId > 45) {
                continue;
            }

            int x = laneArray[row].blockArray[column].x;
            draw_plant(renderer,&plantArray[plantId],x,y);
        }
    }
}

extern void draw_topbar(SDL_Renderer *renderer, topBar *object, TTF_Font *font) {

    object->delayCounter++;
    if (object->delayCounter >= 10) {
        if (object->counter == 0) {
            object->counter = 1;
        } else {
            object->counter = 0;
        }
        object->delayCounter = 0;
    }

    SDL_Rect outerBox = {402, 8, 130, 44};
    SDL_SetRenderDrawColor(renderer, 113, 80, 8, 255);           // Background color
    SDL_RenderFillRect(renderer, &outerBox);

    SDL_Rect innerBox = {450, 12, 78, 36};
    SDL_SetRenderDrawColor(renderer, 230, 214, 157, 255);           // Background color
    SDL_RenderFillRect(renderer, &innerBox);

    char amount[50];
    int textWidth, textHeight;
    sprintf(amount, "%d", object->amount);

    SDL_Color colorBlack = {0,0,0, 255};
    SDL_Surface *surface = TTF_RenderText_Solid(font, amount, colorBlack);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    TTF_SizeText(font, amount, &textWidth, &textHeight);
    SDL_Rect textBox = {456, 14, textWidth,textHeight};
    SDL_RenderCopy(renderer, texture, NULL, &textBox);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);

    blit(renderer, object->texture[object->counter], 400, 5);
}

extern void draw_sidebar(SDL_Renderer *renderer, sideBar *object) {
    int y = 50;
    int x = 50;
    for (int k = 0; k < object->amountTextures; k++) {
        blit(renderer, object->texture[k], x, y);
        y = y + 70;
    }
}