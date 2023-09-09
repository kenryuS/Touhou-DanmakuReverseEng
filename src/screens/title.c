#include <screens/title.h>

void title_render() {
    DrawText("Title", SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 20, GRAY);
}

void title_update(Screens *scr) {
    if (IsKeyPressed(KEY_SPACE)) *scr = GAMEPLAY;
    return;
}
