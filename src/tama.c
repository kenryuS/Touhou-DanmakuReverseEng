#include "tama.h"
#include <raylib.h>

void tama_init(Tama *tama, Vector2 center_pos, TamaType type, Texture2D* texture, bool isFromPlayer, Hitbox_e hb_type) {
    tama->core = sprite_create(POLAR, (Vector2){0.0f,0.0f}, center_pos, 0, texture, hb_type);
    tama->type = type;
    tama->isFromPlayer = isFromPlayer;
    return;
}

void tama_render(Tama *tama) {
    if (!tama->core.isActive) {return;}
    float x = tama->core.pos.x * cos(tama->core.pos.y) + tama->core.aux_pos.x;
    float y = tama->core.pos.x * sin(tama->core.pos.y) + tama->core.aux_pos.y;
    DrawTexture(*(tama->core.texture), x-8, y-8, WHITE);
    return;
}
