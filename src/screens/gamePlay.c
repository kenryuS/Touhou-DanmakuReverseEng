#include <screens/gamePlay.h>
#include <boss.h>

void gameplay_render(Player* pl, BossSprite* boss, Bosses selected_boss) {
    char score[20];
    char fpsstat[10];
    itoa(GetFPS(),fpsstat);
    itoa(pl->status.score, score);
    strncat(fpsstat, " FPS", 10);
    player_render(pl);
    boss_main_render(boss, selected_boss);
    DrawRectangleV((Vector2){2*SCREEN_WIDTH/3.0f, 0}, (Vector2){SCREEN_WIDTH/3.0f + 1, SCREEN_HEIGHT}, MAGENTA);
    DrawText(score, 2*SCREEN_WIDTH/3.0f + 10, 30, 18, BLACK);
    DrawText(fpsstat, SCREEN_WIDTH - 70, SCREEN_HEIGHT - 30, 18, BLACK);
}

void gameplay_update(Screens* scr, Player* pl, BossSprite* boss, Bosses selected_boss) {
    player_update(pl);
    boss_main_update(boss, selected_boss);
    boss_render_healthbar(boss);
    printf("Lives = %d\nHealth = %f\n", boss->lives, boss->health);
    if (IsKeyPressed(KEY_Q)) *scr = ENDING;
    return;
}
