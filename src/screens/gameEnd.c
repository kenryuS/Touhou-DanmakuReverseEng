#include <screens/gameEnd.h>
#include <string.h>

void gameend_render(Player* pl) {
    char temptxt[30] = "Score: ";
    char buff[20];
    itoa(pl->score, buff);
    strncat(temptxt, buff, 20);
    DrawText(temptxt,SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 20, GRAY);
}

void gameend_update(Screens* scr, Player* pl) {
    if (IsKeyPressed(KEY_SPACE)) {
        *scr = TITLE;
        player_init(pl);
    }
    return;
}
