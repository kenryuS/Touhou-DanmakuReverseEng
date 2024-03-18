#include <player.h>

void player_control(Player* player) {
    float speed_multi = 1.0f;
    Vector2 delta_pos = {0.0f, 0.0f};
    if (IsKeyDown(KEY_LEFT_SHIFT)) speed_multi = PLAYER_SPEED_SLOWMULTI;
    if (IsKeyDown(KEY_UP) && player->core.pos.y > 0) delta_pos.y = -1 * PLAYER_SPEED * speed_multi;
    if (IsKeyDown(KEY_DOWN) && player->core.pos.y < SCREEN_HEIGHT) delta_pos.y = PLAYER_SPEED * speed_multi;
    if (IsKeyDown(KEY_LEFT) && player->core.pos.x > 0) delta_pos.x = -1 * PLAYER_SPEED * speed_multi;
    if (IsKeyDown(KEY_RIGHT) && player->core.pos.x < 2*((float)SCREEN_WIDTH)/3) delta_pos.x = PLAYER_SPEED * speed_multi;
    sprite_translate(&(player->core), delta_pos);
    if (IsKeyDown(KEY_Z)) {player_shoot(player);}
}

void player_render(Player* player) {
    if (!IsKeyDown(KEY_LEFT_SHIFT)) hitbox_render(player->core.hitbox);
    DrawCircle(player->core.pos.x, player->core.pos.y, 20, RED);
    if (IsKeyDown(KEY_LEFT_SHIFT)) hitbox_render(player->core.hitbox);
    for (int i = 0; i < PLAYER_TAMA_NUM; i++) {
        tama_render(&(player->tama[i]));
    }
}

void player_update(Player* player) {
    player_control(player);
    player_tama_update(player);
    player->core.hitbox.core.circle.center = player->core.pos;
    player->core.ticks++;
}

Player player_init() {
    Player player = {};
    player.status = (Player_Status){0,0};
    player.core = sprite_create(RECT, (Vector2){SCREEN_WIDTH/3.0f, 800.0f}, (Vector2){0.0f,0.0f}, 1, (Texture2D){}, HB_CIRCLE);
    player.core.hitbox.core.circle.radius = 15;
    player.core.hitbox.core.circle.center = player.core.pos;
    extern const unsigned char player_tama_png[];
    extern const unsigned int player_tama_png_len;
    Image player_tama_img = LoadImageFromMemory(".png", player_tama_png, player_tama_png_len);
    for (int i = 0; i < PLAYER_TAMA_NUM; i++) {
        tama_init(&(player.tama[i]), (Vector2){player.core.pos.x, player.core.pos.y}, NORMAL, player_tama_img, true, HB_CIRCLE);
    }
    UnloadImage(player_tama_img);
    return player;
}

void player_shoot(Player* player) {
    if (player->core.ticks % (60 / PLAYER_TAMA_SHOT_SPEED) != 0) return;
    for (int i = 0; i < PLAYER_TAMA_NUM; i++) {
        Tama* target = &(player->tama[i]);
        if (target->core.isActive == false) {
            target->core.isActive = true;
            target->core.pos.y = PI / -2.0f;
            target->core.pos.x = 0;
            target->core.aux_pos = player->core.pos;
            break;
        }
    }
}

void player_tama_update(Player* player) {
    for (int i = 0; i < PLAYER_TAMA_NUM; i++) {
        Tama* target = &(player->tama[i]);
        if (target->core.isActive) {
            sprite_translate(&(target->core), (Vector2){PLAYER_TAMA_SPEED, 0.0f});
            target->core.ticks += 1;
            if (target->core.pos.x > 1000) {
                target->core.isActive = false;
                target->core.ticks = 0;
            }
        }
    }
}
