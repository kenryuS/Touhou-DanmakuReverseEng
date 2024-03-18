#include "player.h"
#include <raylib.h>
#include <screens/gameEnd.h>
#include <string.h>

void gameend_render(Player* pl) {
    char temptxt[30] = "Score: ";
    char buff[20];
    itoa(pl->status.score, buff);
    strncat(temptxt, buff, 20);
    DrawText(temptxt,SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 20, GRAY);
}

void gameend_update(Screens* scr, Player* pl) {
    if (IsKeyPressed(KEY_SPACE)) {
        *scr = TITLE;
        for (int i = 0; i < PLAYER_TAMA_NUM; i++) {
            UnloadTexture((pl->tama[i]).core.texture);
        }
        *pl = player_init();
    }
    return;
}
