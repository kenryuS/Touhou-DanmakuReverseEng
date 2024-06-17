#include <screens/gamePlay.h>

void gameplay_render(Game *game) {
    char score[20];
    char global_time[12];
    char fpsstat[10];
    itoa(GetFPS(),fpsstat);
    itoa(game->player.status.score, score);
    snprintf(global_time, sizeof(global_time), "%f", game->time);
    strncat(fpsstat, " FPS", 10);
    player_render(&(game->player));
    boss_main_render(&(game->boss), game->selected_boss);
    boss_render_healthbar(&(game->boss));
    DrawRectangleV((Vector2){2*SCREEN_WIDTH/3.0f, 0}, (Vector2){SCREEN_WIDTH/3.0f + 1, SCREEN_HEIGHT}, MAGENTA);
    DrawText(score, 2*SCREEN_WIDTH/3.0f + 10, 30, 18, BLACK);
    DrawText(fpsstat, SCREEN_WIDTH - 70, SCREEN_HEIGHT - 30, 18, BLACK);
    DrawText(global_time, SCREEN_WIDTH - 70, SCREEN_HEIGHT - 60, 18, BLACK);
}

void gameplay_update(Game *game) {
    if (game->inited == 0) {
        game->inited = 1;
        game->player = player_init();
        boss_main_init(&(game->boss), game->selected_boss);
        return;
    }
    player_update(&(game->player));
    boss_main_update(&(game->boss), game->selected_boss);
    if (IsKeyPressed(KEY_Q)) game->currentScr = ENDING;
    return;
}
