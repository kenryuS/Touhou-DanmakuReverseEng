#include <screens/gameSetup.h>

void game_setup_render(Game *game) {
    DrawText("Press Z to start the game", SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 24, GRAY);
}

void game_setup_update(Game *game) {
    if (IsKeyPressed(KEY_Z)) {
        game->selected_boss = DEMO;
        game->currentScr = GAMEPLAY;
    }
    return;
}