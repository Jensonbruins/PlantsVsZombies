/*
 *  @since: v1.0.0
 *  @author: Jenson Bruins
 */

void renderOuterFieldTile(int startX, int startY) {
    int previousX = startX;
    int previousY = startY;

    int b = 0;
    for (int a = 0; a < 45; a++) {
        if (b < 8) {
            SDL_Rect outerTile = {previousX, previousY, OUTER_TILE_SIZE, OUTER_TILE_SIZE};
            SDL_SetRenderDrawColor(renderer, 124, 157, 54, 255);
            SDL_RenderFillRect(renderer, &outerTile);

            SDL_Rect innerTile = {previousX + INNER_TILE_OFFSET, previousY + INNER_TILE_OFFSET, OUTER_TILE_SIZE - INNER_TILE_OFFSET * 2, OUTER_TILE_SIZE - INNER_TILE_OFFSET * 2};
            SDL_SetRenderDrawColor(renderer, 159, 186, 79, 255);
            SDL_RenderFillRect(renderer, &innerTile);

            previousX = previousX + OUTER_TILE_SIZE;
            b++;
        } else {
            b = 0;
            previousX = startX;
            previousY = previousY + OUTER_TILE_SIZE;
        }
    }
}

void renderSun(int x, int y) {
    SDL_Rect sunBody = {x,y,15,15};
    SDL_SetRenderDrawColor(renderer, 247, 202, 24, 255);
    SDL_RenderFillRect(renderer, &sunBody);
}