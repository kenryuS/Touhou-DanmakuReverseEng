#include "config.h"
#include <screens/gamePlay.h>

void gameplay_render(Player* pl) {
    char score[20];
    char fpsstat[10];
    itoa(GetFPS(),fpsstat);
    itoa(pl->score, score);
    strncat(fpsstat, " FPS", 10);
    DrawRectangleV((Vector2){2*SCREEN_WIDTH/3.0f, 0}, (Vector2){SCREEN_WIDTH/3.0f + 1, SCREEN_HEIGHT}, MAGENTA);
    DrawText(score, 2*SCREEN_WIDTH/3.0f + 10, 30, 18, BLACK);
    DrawText(fpsstat, SCREEN_WIDTH - 70, SCREEN_HEIGHT - 30, 18, BLACK);
}

void gameplay_update(Screens *scr) {
    if (IsKeyPressed(KEY_Q)) *scr = ENDING;
    return;
}
