#include <player.h>

void player_control(Player* player) {
    float speed_multi = 1.0f;
    if (IsKeyDown(KEY_LEFT_SHIFT)) speed_multi = PLAYER_SPEED_SLOWMULTI;
    if (IsKeyDown(KEY_UP) && player->y > 0) player->y -= PLAYER_SPEED * speed_multi;
    if (IsKeyDown(KEY_DOWN) && player->y < SCREEN_HEIGHT) player->y += PLAYER_SPEED * speed_multi;
    if (IsKeyDown(KEY_LEFT) && player->x > 0) player->x -= PLAYER_SPEED * speed_multi;
    if (IsKeyDown(KEY_RIGHT) && player->x < 2*SCREEN_WIDTH/3) player->x += PLAYER_SPEED * speed_multi;
}

void player_render(Player* player) {
    DrawCircle(player->x, player->y, 20, RED);
}
