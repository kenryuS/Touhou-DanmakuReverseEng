#include "player.h"
#include <main.h>

struct Player* player = &(struct Player){(float)SCREEN_WIDTH/3, 800.0f, false, 0, 0, 0};

Screens currentScr = TITLE;

int globalTick = 0;

void update(void) {
    if (currentScr == TITLE) {
        title_update(&currentScr);
    }
    if (currentScr == GAMEPLAY) {
        gameplay_update(&currentScr);
        player_update(player);
        if (IsKeyDown(KEY_PAGE_UP)) player->score++;
        if (IsKeyDown(KEY_PAGE_DOWN)) player->score--;
    }
    if (currentScr == ENDING) gameend_update(&currentScr, player);
    globalTick++;
    return;
}

void draw(void) {BeginDrawing();
    ClearBackground(RAYWHITE);
    if (currentScr == TITLE) {
        title_render();
    }
    if (currentScr == GAMEPLAY) {
        player_render(player);
        gameplay_render(player);
    }
    if (currentScr == ENDING) gameend_render(player);
EndDrawing();}

int main(int argc, char** argv) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
    SetTargetFPS(FPS);
    player_init(player);

    while (!WindowShouldClose()) {
        update();
        draw();
    }

    CloseWindow();
    return 0;
}
