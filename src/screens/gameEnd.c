#include <screens/gameEnd.h>

void gameend_render(Game *game) {
    char temptxt[30] = "Score: ";
    char buff[20];
    itoa(game->player.status.score, buff);
    strncat(temptxt, buff, 20);
    DrawText(temptxt,SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 20, GRAY);
}

void gameend_update(Game *game) {
    if (IsKeyPressed(KEY_SPACE)) {
        game->currentScr = TITLE;
        for (int i = 0; i < PLAYER_TAMA_NUM; i++) {
            UnloadTexture(*(game->player.tama[i]).core.texture);
        }
        game->player = player_init();
        game->inited = 0;
    }
    return;
}
