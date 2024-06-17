#include <main.h>

void update(Game *game) {
    switch (game->currentScr) {
        case TITLE: {
            title_update(game);
            break;
        }
        case GAMESETUP: {
            game_setup_update(game);
            break;
        }
        case GAMEPLAY: {
            gameplay_update(game);
            break;
        }
        case ENDING: {
            gameend_update(game);
            break;
        }
    }
    game->globalTick++;
    game->time += GetFrameTime();
    return;
}

void draw(Game *game) {BeginDrawing();
    ClearBackground(RAYWHITE);
    switch (game->currentScr) {
        case TITLE: {
            title_render(game);
            break;
        }
        case GAMESETUP: {
            game_setup_render(game);
            break;
        }
        case GAMEPLAY: {
            gameplay_render(game);
            break;
        }
        case ENDING: {
            gameend_render(game);
            break;
        }
    }
EndDrawing();}

int main(int argc, char** argv) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
    SetTargetFPS(FPS);

    Game game = {
        .currentScr = TITLE,
        .player = { 0 },
        .boss = { 0 },
        .selected_boss = -1,
        .globalTick = 0,
        .inited = 0
    };

    while (!WindowShouldClose()) {
        update(&game);
        draw(&game);
    }

    CloseWindow();
    return 0;
}
