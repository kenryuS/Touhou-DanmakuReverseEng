#include <main.h>

int main(int argc, char** argv) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
    SetTargetFPS(FPS);

    Game game = { 0 };
    game_init(&game);

    while (!WindowShouldClose()) {
        game_update(&game);
        game_draw(&game);
    }

    CloseWindow();
    return 0;
}
