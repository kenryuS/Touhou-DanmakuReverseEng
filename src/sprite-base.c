#include <sprite-base.h>

unsigned int SpriteIDCounter = 0;

Sprite sprite_create(enum Position_Modes mode, Vector2 pos, Vector2 aux_pos, bool isActive, Texture2D* tex, Hitbox_e hb_type) {
    Hitbox hb;
    hb.type = hb_type;
    switch (hb_type) {
        case HB_CIRCLE: {
            hb.core.circle = (Hitbox_Circle){0};
            break;
        }
        case HB_RECT: {
            hb.core.rect = (Hitbox_Rect){0};
            break;
        }
        case HB_LINE: {
            hb.core.line = (Hitbox_Line){0};
            break;
        }
    }
    return (Sprite){++SpriteIDCounter, mode, pos, aux_pos, tex, hb, isActive, 0, 0};
}

void sprite_translate(Sprite *target, Vector2 delta) {
    float deltaTime = GetFrameTime();
    target->pos = (Vector2){target->pos.x + delta.x*deltaTime, target->pos.y + delta.y*deltaTime};
    return;
}

bool sprite_isRect(Sprite *target) {
    return (target->mode == RECT);
}

bool sprite_isPolar(Sprite *target) {
    return (target->mode == POLAR);
}
