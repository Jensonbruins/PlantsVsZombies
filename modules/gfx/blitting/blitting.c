//
// Created by jenson on 12-10-20.
//

#include "blitting.h"

static void blit(SDL_Renderer *renderer, SDL_Texture *txtr, int x, int y);
static void helper_sidebar_item(SDL_Renderer *renderer, sideBar *object, int amount, int x, int y, int cost, int item);
static void helper_sidebar(SDL_Renderer *renderer, int x, int y, int color);
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

extern void draw_sidebar(SDL_Renderer *renderer, sideBar *object, topBar *topBarObject) {
    int y = 50;
    int x = 50;

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    blit(renderer, object->texture[0], x, y); // PeashooterSeed
    helper_sidebar_item(renderer, object, topBarObject->amount, x, y, 100, 1);

    y = y + 70;

    blit(renderer, object->texture[1], x, y); // SunFlowerSeed
    helper_sidebar_item(renderer, object, topBarObject->amount, x, y, 50, 2);
}

static void helper_sidebar_item(SDL_Renderer *renderer,sideBar *object, int amount, int x, int y, int cost, int item) {
    if (amount < cost) {
        helper_sidebar(renderer, x, y, 0);
        if (object->selection == item) {
            object->selection = 0;
        }
    } else if (object->selection == item) {
        helper_sidebar(renderer, x, y, 1);
    }
}

static void helper_sidebar(SDL_Renderer *renderer, int x, int y, int color) {
    if (color == 0) {
        SDL_SetRenderDrawColor(renderer, 105,105,105, 160);
        SDL_Rect insufficientFunds = {x, y, 107, 66};
        SDL_RenderFillRect(renderer, &insufficientFunds);
    } else {
        SDL_SetRenderDrawColor(renderer, 255,0,0, 255);
        SDL_Rect topToRight = {x, y+3, 20, 6};
        SDL_Rect topToLeft = {x+84, y+3, 20, 6};
        SDL_Rect topLeftToBottom = {x, y+3, 6, 20};
        SDL_Rect topRightToBottom = {x+100, y+3, 6, 20};
        SDL_Rect bottomLeftToTop = {x, y+46, 6, 20};
        SDL_Rect bottomRightToTop = {x+100, y+46, 6, 20};
        SDL_Rect bottomToRight = {x, y + 60, 20, 6};
        SDL_Rect bottomToLeft = {x + 84, y + 60, 20, 6};
        SDL_RenderFillRect(renderer, &topToRight);
        SDL_RenderFillRect(renderer, &topToLeft);
        SDL_RenderFillRect(renderer, &topLeftToBottom);
        SDL_RenderFillRect(renderer, &topRightToBottom);
        SDL_RenderFillRect(renderer, &bottomLeftToTop);
        SDL_RenderFillRect(renderer, &bottomRightToTop);
        SDL_RenderFillRect(renderer, &bottomToRight);
        SDL_RenderFillRect(renderer, &bottomToLeft);

    }
}