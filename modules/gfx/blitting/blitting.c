//
// Created by jenson on 12-10-20.
//

#include "blitting.h"

static void blit(SDL_Renderer *renderer, SDL_Texture *txtr, int x, int y);

static void helper_sidebar_item(SDL_Renderer *renderer, sideBar *object, int amount, int x, int y, int cost, int item);

static void helper_sidebar(SDL_Renderer *renderer, int x, int y, int color);

static void blit(SDL_Renderer *renderer, SDL_Texture *txtr, int x, int y) {
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(txtr, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(renderer, txtr, NULL, &dest);
}

extern void draw_pre_game(SDL_Renderer *renderer, SDL_Texture *preGameTexture, TTF_Font *font) {
    blit(renderer, preGameTexture, 350, 0);

    int textWidth, textHeight;

    SDL_Color colorWhite = {255, 255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Solid(font, "Press ENTER to start the game!", colorWhite);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    TTF_SizeText(font, "Press ENTER to start the game!", &textWidth, &textHeight);
    SDL_Rect textBox = {600, 600, textWidth, textHeight};
    SDL_RenderCopy(renderer, texture, NULL, &textBox);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

extern void draw_background(SDL_Renderer *renderer, SDL_Texture *backgroundTexture) {
    blit(renderer, backgroundTexture, 0, 0);
}

extern void draw_defeat_game(SDL_Renderer *renderer, SDL_Texture *preGameTexture, TTF_Font *font) {
    blit(renderer, preGameTexture, 350, 0);

    int textWidth, textHeight;

    SDL_Color colorWhite = {255, 255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Solid(font, "You have failed! The zombies attacked your house", colorWhite);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    TTF_SizeText(font, "You have failed! The zombies attacked your house", &textWidth, &textHeight);
    SDL_Rect textBox = {500, 600, textWidth, textHeight};
    SDL_RenderCopy(renderer, texture, NULL, &textBox);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

extern void draw_zombie(SDL_Renderer *renderer, zombie objects[50], int amount) {
    for (int k = 0; k < amount; k++) {
        if (objects[k].health > 0) {
            int y;
            switch (objects[k].lane) {
                case (0):
                    y = 50;
                    break;
                case (1):
                    y = 200;
                    break;
                case (2):
                    y = 360;
                    break;
                case (3):
                    y = 470;
                    break;
                case (4):
                    y = 640;
                    break;
            }
            if (objects[k].state == 0) {

                blit(renderer, objects[k].textureWalk[objects[k].walkCounter], objects[k].x, y);

                objects[k].delayCounter++;

                if (objects[k].delayCounter >= 5) {
                    objects[k].walkCounter++;
                    objects[k].delayCounter = 0;
                }

                if (objects[k].walkCounter >= objects[k].amountWalkTexture) {
                    objects[k].walkCounter = 0;
                }
            }

            if (objects[k].state == 1) {
                blit(renderer, objects[k].textureAttack[objects[k].attackCounter], objects[k].x, y);

                objects[k].delayCounter++;

                if (objects[k].delayCounter >= 5) {
                    objects[k].attackCounter++;
                    objects[k].delayCounter = 0;
                }

                if (objects[k].attackCounter >= objects[k].amountAttackTexture) {
                    objects[k].attackCounter = 0;
                }
            }
        }

    }
}

extern void draw_plant(SDL_Renderer *renderer, plant *object, int x, int y) {
    if (object->health > 0) {
        if (object->state == 0 || object->state == 1) {
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
    for (int row = 0; row <= 4; row++) {
        int y = laneArray[row].y;
        for (int column = 0; column <= 8; column++) {
            int plantId = laneArray[row].blockArray[column].plantId;
            if (plantId > 45) {
                continue;
            }

            int x = laneArray[row].blockArray[column].x;
            draw_plant(renderer, &plantArray[plantId], x, y);
        }
    }
}

extern void draw_projectile(SDL_Renderer *renderer, projectile object[50]) {
    for (int k = 0; k < 50; k++) {
        if (object[k].alive > 0) {
            blit(renderer, object[k].texture, object[k].x, object[k].y);
        }
    }
}

extern void draw_sun(SDL_Renderer *renderer, sun object[20]) {
    for (int k = 0; k < 20; k++) {
        if (object[k].alive > 0) {
            object[k].delayCounter++;
            if (object[k].delayCounter >= 20) {
                if (object[k].counter == 0) {
                    object[k].counter = 1;
                } else {
                    object[k].counter = 0;
                }
                object[k].delayCounter = 0;
            }
            blit(renderer, object[k].texture[object[k].counter], object[k].x, object[k].y);
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

    SDL_Color colorBlack = {0, 0, 0, 255};
    SDL_Surface *surface = TTF_RenderText_Solid(font, amount, colorBlack);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    TTF_SizeText(font, amount, &textWidth, &textHeight);
    SDL_Rect textBox = {456, 14, textWidth, textHeight};
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

    y = y + 70;

    blit(renderer, object->texture[2], x, y); // Walnut
    helper_sidebar_item(renderer, object, topBarObject->amount, x, y, 50, 3);
}

static void helper_sidebar_item(SDL_Renderer *renderer, sideBar *object, int amount, int x, int y, int cost, int item) {
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
        SDL_SetRenderDrawColor(renderer, 105, 105, 105, 160);
        SDL_Rect insufficientFunds = {x, y, 107, 66};
        SDL_RenderFillRect(renderer, &insufficientFunds);
    } else {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect topToRight = {x, y + 3, 20, 6};
        SDL_Rect topToLeft = {x + 84, y + 3, 20, 6};
        SDL_Rect topLeftToBottom = {x, y + 3, 6, 20};
        SDL_Rect topRightToBottom = {x + 100, y + 3, 6, 20};
        SDL_Rect bottomLeftToTop = {x, y + 46, 6, 20};
        SDL_Rect bottomRightToTop = {x + 100, y + 46, 6, 20};
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