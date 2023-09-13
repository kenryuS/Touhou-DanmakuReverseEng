#include "tama.h"
#include <player.h>
#include <raylib.h>

void player_control(Player* player) {
    float speed_multi = 1.0f;
    if (IsKeyDown(KEY_LEFT_SHIFT)) speed_multi = PLAYER_SPEED_SLOWMULTI;
    if (IsKeyDown(KEY_UP) && player->y > 0) player->y -= PLAYER_SPEED * speed_multi;
    if (IsKeyDown(KEY_DOWN) && player->y < SCREEN_HEIGHT) player->y += PLAYER_SPEED * speed_multi;
    if (IsKeyDown(KEY_LEFT) && player->x > 0) player->x -= PLAYER_SPEED * speed_multi;
    if (IsKeyDown(KEY_RIGHT) && player->x < 2*((float)SCREEN_WIDTH)/3) player->x += PLAYER_SPEED * speed_multi;
    if (IsKeyDown(KEY_Z)) {player_shoot(player);}
}

void player_render(Player* player) {
    DrawCircle(player->x, player->y, 20, RED);
    for (int i = 0; i < PLAYER_TAMA_NUM; i++) {
        tama_render(&(player->tama[i]));
    }
}

void player_update(Player* player) {
    player_control(player);
    player_tama_update(player);
    player->tick++;
}

void player_init(Player* player) {
    player->didHit = false;
    player->score = 0;
    player->x = SCREEN_WIDTH/3.0f;
    player->y = 800.0f;
    player->tick = 0;
    extern const unsigned char player_tama_png[];
    extern const unsigned int player_tama_png_len;
    Image player_tama_img = LoadImageFromMemory(".png", player_tama_png, player_tama_png_len);
    for (int i = 0; i < PLAYER_TAMA_NUM; i++) {
        tama_init(&(player->tama[i]), player->x, player->y, NORMAL, player_tama_img, true);
    }
    UnloadImage(player_tama_img);
    printf("Tama Texture Loaded\n");
}

void player_shoot(Player* player) {
    if (player->tick % (60 / PLAYER_TAMA_SHOT_SPEED) != 0) return;
    for (int i = 0; i < PLAYER_TAMA_NUM; i++) {
        if (player->tama[i].isActive == false) {
            player->tama[i].isActive = true;
            player->tama[i].t = PI / -2.0f;
            player->tama[i].r = 0;
            tama_setCenterPos(&(player->tama[i]), player->x, player->y);
            printf("Tama Spawned\n");
            break;
        }
    }
}

void player_tama_update(Player* player) {
    for (int i = 0; i < PLAYER_TAMA_NUM; i++) {
        if (player->tama[i].isActive) {
            player->tama[i].r += PLAYER_TAMA_SPEED;
            if (player->tama[i].r > 1000) {player->tama[i].isActive = false; printf("Tama Deactivated\n");}
        }
    }
}