#include "tama.h"
#include <raylib.h>

void tama_init(Tama *tama, float cx, float cy, TamaType type, Image img, bool isFromPlayer) {
    tama->cx = cx;
    tama->cy = cy;
    tama->r = 0.0f;
    tama->t = 0.0f;
    tama->type = type;
    tama->isFromPlayer = isFromPlayer;
    tama->texture = LoadTextureFromImage(img);
    tama->isActive = false;
    return;
}

void tama_setCenterPos(Tama *tama, float x, float y) {
    tama->cx = x;
    tama->cy = y;
    return;
}

void tama_setPolPos(Tama *tama, float r, float t) {
    tama->r = r;
    tama->t = t;
    return;
}

void tama_render(Tama *tama) {
    if (!tama->isActive) {return;}
    float x = tama->r * cos(tama->t) + tama->cx;
    float y = tama->r * sin(tama->t) + tama->cy;
    DrawTexture(tama->texture, x-8, y-8, WHITE);
    //DrawCircle(x, y, 10, YELLOW);
    return;
}