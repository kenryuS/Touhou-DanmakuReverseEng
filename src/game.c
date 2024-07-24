#include <game.h>

#include <screens/title.h>
#include <screens/gameSetup.h>
#include <screens/gamePlay.h>
#include <screens/gameEnd.h>

void game_init(Game* game) {
    game->currentScr = TITLE;
    game->player = (Player){ 0 };
    game->boss = (BossSprite){ 0 };
    game->selected_boss = -1;
    game->time = 0.0f;
    game->globalTick = 0;
    game->inited = 0;
    game->GamePlaneRect = (Local_Cordinate_System){
        (Vector2){SCREEN_WIDTH * 7.0f / 20.0f, SCREEN_WIDTH * 3.0f / 8.0f},
        (Vector2){1.0f, -1.0f},
        RECT
    };
    game->GamePlanePolar = (Local_Cordinate_System){
        (Vector2){SCREEN_WIDTH * 7.0f / 20.0f, SCREEN_WIDTH * 3.0f / 8.0f},
        (Vector2){1.0f, -1.0f},
        POLAR
    };
}

void game_update(Game* game) {
    switch (game->currentScr) {
        case TITLE: {
            title_update(game);
            break;
        }
        case GAMESETUP: {
            gamesetup_update(game);
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

void game_draw(Game* game) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    switch (game->currentScr) {
        case TITLE: {
            title_render(game);
            break;
        }
        case GAMESETUP: {
            gamesetup_render(game);
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
    EndDrawing();
}
