//
// Created by jenson on 12-10-20.
//

#include "input.h"
static void proper_shutdown(SDL_Renderer *renderer, SDL_Window *window, TTF_Font *font);
static void handle_click(int x, int y,SDL_Renderer *renderer, lane laneArray[5], plant plantObjects[45], sideBar *sideBarObject);
static int handle_click_helper(int x);

extern void process_input(SDL_Window *window, SDL_Renderer *renderer, TTF_Font *font, lane laneArray[5], plant plantObjects[45], sideBar *sideBarObject) {
    SDL_Event event;
    int mouseX;
    int mouseY;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                proper_shutdown(renderer, window, font);
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                SDL_GetMouseState(&mouseX,&mouseY);
                handle_click(mouseX,mouseY,renderer, laneArray,plantObjects, sideBarObject);
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                    proper_shutdown(renderer, window, font);
                    exit(0);
                }
                break;
            default:
                break;
        }
    }
}

static void handle_click(int x, int y,SDL_Renderer *renderer , lane laneArray[5], plant plantObjects[45], sideBar *sideBarObject) {
    int lane1start = 120;
    int lane2start = 238;
    int lane3start = 380;
    int lane4start = 520;
    int lane5start = 660;
    int lane5stop = 800;

    int grid1start = 392;
    int grid9stop = 1529;

//    printf("%d,%d", x, y);
    int sideBarStart = 50;

    for (int k = 1; k < 3; k++) {
        if (x > 50 && x < 107) {
            if (y > sideBarStart && y < (sideBarStart + 66)) {
                if (sideBarObject->selection == k) {
                    sideBarObject->selection = 0;
                } else {
                    sideBarObject->selection = k;
                }
            }
        }
        sideBarStart = sideBarStart + 70;
    }

    if (sideBarObject->selection != 0) {
        if (y > lane1start && y < lane2start) {
            if (x > grid1start && x < grid9stop) {
                int helper_id = handle_click_helper(x);
                int id = 0 + helper_id;
                laneArray[0].blockArray[helper_id].plantId = id;
                init_plant(renderer, &plantObjects[id], sideBarObject->selection);
            }
        } else if (y > lane2start && y < lane3start) {
            if (x > grid1start && x < grid9stop) {
                int helper_id = handle_click_helper(x);
                int id = 9 + helper_id;
                laneArray[1].blockArray[helper_id].plantId = id;
                init_plant(renderer, &plantObjects[id], sideBarObject->selection);
            }
        } else if (y > lane3start && y < lane4start) {
            if (x > grid1start && x < grid9stop) {
                int helper_id = handle_click_helper(x);
                int id = 18 + helper_id;
                laneArray[2].blockArray[helper_id].plantId = id;
                init_plant(renderer, &plantObjects[id], sideBarObject->selection);
            }
        } else if (y > lane4start && y < lane5start) {
            if (x > grid1start && x < grid9stop) {
                int helper_id = handle_click_helper(x);
                int id = 27 + helper_id;
                laneArray[3].blockArray[helper_id].plantId = id;
                init_plant(renderer, &plantObjects[id], sideBarObject->selection);
            }
        } else if (y > lane5start && y < lane5stop) {
            if (x > grid1start && x < grid9stop) {
                int helper_id = handle_click_helper(x);
                int id = 36 + helper_id;
                laneArray[4].blockArray[helper_id].plantId = id;
                init_plant(renderer, &plantObjects[id], sideBarObject->selection);
            }
        }
    }
}

static int handle_click_helper(int x) {
    int grid1start = 392;
    int grid2start = 525;
    int grid3start = 638;
    int grid4start = 777;
    int grid5start = 897;
    int grid6start = 1033;
    int grid7start = 1154;
    int grid8start = 1277;
    int grid9start = 1396;
    int grid9stop = 1529;

    if (x > grid1start && x < grid2start) {
        return 0;
    } else if (x > grid2start && x < grid3start) {
        return 1;
    } else if (x > grid3start && x < grid4start) {
        return 2;
    } else if (x > grid4start && x < grid5start) {
        return 3;
    } else if (x > grid5start && x < grid6start) {
        return 4;
    } else if (x > grid6start && x < grid7start) {
        return 5;
    } else if (x > grid7start && x < grid8start) {
        return 6;
    } else if (x > grid8start && x < grid9start) {
        return 7;
    } else if (x > grid9start && x < grid9stop) {
        return 8;
    }
    return 9;
}

static void proper_shutdown(SDL_Renderer *renderer, SDL_Window *window, TTF_Font *font) {
    Mix_CloseAudio();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}