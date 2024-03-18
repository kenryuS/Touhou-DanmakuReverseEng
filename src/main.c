#include "boss.h"
#include <main.h>

Player* player = NULL;
BossSprite boss = {};
Bosses selected_boss = 0;

Screens currentScr = TITLE;

int globalTick = 0;

void update(void) {
    switch (currentScr) {
        case TITLE: {
            title_update(&currentScr);
            break;
        }
        case GAMEPLAY: {
            gameplay_update(&currentScr, player, &boss, selected_boss);
            break;
        }
        case ENDING: {
            gameend_update(&currentScr, player);
            break;
        }
    }
    globalTick++;
    return;
}

void draw(void) {BeginDrawing();
    ClearBackground(RAYWHITE);
    switch (currentScr) {
        case TITLE: {
            title_render();
            break;
        }
        case GAMEPLAY: {
            gameplay_render(player, &boss, selected_boss);
            break;
        }
        case ENDING: {
            gameend_render(player);
            break;
        }
    }
EndDrawing();}

int main(int argc, char** argv) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
    SetTargetFPS(FPS);
    Player pl = player_init();
    player = &pl;
    selected_boss = TEST;
    boss_main_init(boss, selected_boss);

    while (!WindowShouldClose()) {
        update();
        draw();
    }

    CloseWindow();
    return 0;
}
