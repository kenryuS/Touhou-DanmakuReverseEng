#include <sprite-base.h>

unsigned int SpriteIDCounter = 0;

void sprite_create(Local_Cordinate_System* cordSys, Vector2 initPos, bool isActive, Texture2D* tex, Hitbox_e hb_type, Sprite* dest) {
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
    dest->cord = (Local_Cordinate){cordSys, initPos};
    dest->hitbox = hb;
    dest->id = ++SpriteIDCounter;
    dest->isActive = isActive;
    dest->texture = tex;
    dest->ticks = 0;
    dest->time = 0.0f;
    return;
}

void sprite_translate(Sprite *target, Vector2 delta) {
    float deltaTime = GetFrameTime();
    target->cord.cord = (Vector2){target->cord.cord.x + delta.x*deltaTime, target->pos.y + delta.y*deltaTime};
    return;
}

bool sprite_isRect(Sprite *target) {
    return (target->cord.cord_sys->mode == RECT);
}

bool sprite_isPolar(Sprite *target) {
    return (target->cord.cord_sys->mode == POLAR);
}
