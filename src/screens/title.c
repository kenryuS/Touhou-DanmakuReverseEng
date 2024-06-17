#include <screens/title.h>

void title_render(Game *game) {
    DrawText("Title", SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 20, GRAY);
}

void title_update(Game *game) {
    if (IsKeyPressed(KEY_SPACE)) game->currentScr = GAMESETUP;
    return;
}
