#include <screens.h>

void screens_render_title(void) {
    DrawText("Title", SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 20, BLACK);
}

void screens_render_gameplay(void) {
    DrawText("Game Play", SCREEN_WIDTH/3, SCREEN_HEIGHT/2, 20, BLACK);
    DrawRectangle(2*SCREEN_WIDTH/3, 0, SCREEN_WIDTH/3 + 1, SCREEN_HEIGHT, MAGENTA);
}

void screens_render_ending(void) {
    DrawText("Ending", SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 20, BLACK);
}

void screens_render(Screens* scr) {
    switch (*scr) {
        case TITLE:
            screens_render_title();
            break;
        case GAMEPLAY:
            screens_render_gameplay();
            break;
        case ENDING:
            screens_render_ending();
            break;
    }
}

void screens_update_title(Screens* scr) {
    if (IsKeyPressed(KEY_SPACE)) *scr = GAMEPLAY;
}

void screens_update_gameplay(Screens* scr) {
    if (IsKeyPressed(KEY_Q)) *scr = ENDING;
}

void screens_update_ending(Screens* scr) {
    if (IsKeyPressed(KEY_SPACE)) *scr = TITLE;
}

void screens_update(Screens* scr) {
    switch (*scr) {
        case TITLE:
            screens_update_title(scr);
            break;
        case GAMEPLAY:
            screens_update_gameplay(scr);
            break;
        case ENDING:
            screens_update_ending(scr);
            break;
    }
}

