/*
 *  @since: v1.0.0
 *  @author: Jenson Bruins
 */

#define SCREEN_WIDTH   1600
#define SCREEN_HEIGHT  900
#define BACKGROUND_COLOR 122, 62, 0, 255

#define OUTER_TILE_SIZE 160
#define INNER_TILE_OFFSET 5

/*
 * Timer creations
 */
Uint32 sunTimer = 0;

/*
 * Timestamps
 */
Uint32 sunTimerTimestamp = 0;

/*
 * SDL defines
 */
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

/*
 * Struct defines
 */
typedef struct _rgbaColor_ {
    int r;
    int g;
    int b;
    int a;
} rgbaColor;
