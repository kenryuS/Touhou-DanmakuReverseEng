#include <main.h>

struct Player* player = &(struct Player){SCREEN_WIDTH/3, 800.0f, false, false};

Screens currentScr = TITLE;

void update(void) {
    if (currentScr == GAMEPLAY) player_control(player);
    screens_update(&currentScr);
    return;
}

void draw(void) {BeginDrawing();
    ClearBackground(RAYWHITE);
    if (currentScr == GAMEPLAY) player_render(player);
    screens_render(&currentScr);
EndDrawing();}

int main(int argc, char** argv) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
    SetTargetFPS(FPS);

    while (!WindowShouldClose()) {
        update();
        draw();
    }

    CloseWindow();
    return 0;
}
