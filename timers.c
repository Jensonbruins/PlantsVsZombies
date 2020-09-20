/*
 *  @since: v1.0.0
 *  @author: Jenson Bruins
 */

void renderSunProcess() {
    Uint32 currentTime = SDL_GetTicks();

    if (sunTimerTimestamp == 0) {
        sunTimerTimestamp = (Uint32)random_int(5000, 6000);
    }

    if (sunTimerTimestamp < (currentTime - sunTimer)) {
        printf("test");
//       kK renderSun(random_int(100,1500), random_int(100,800));
        renderSun(50,50);
        sunTimer = SDL_GetTicks();
        sunTimerTimestamp = 0;
    }
}
