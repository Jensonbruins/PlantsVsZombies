/*
 *  @since: v1.0.0
 *  @author: Jenson Bruins
 */

SDL_Texture *load_texture(char *filename)
{
    SDL_Texture *txtr;
    txtr = IMG_LoadTexture(renderer, filename);
    return txtr;
}

void blit(SDL_Texture *txtr, int x, int y, int center)
{
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