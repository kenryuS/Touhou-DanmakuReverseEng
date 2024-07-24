#ifndef SPRITE_BASE_H_
#define SPRITE_BASE_H_

#include <raylib.h>
#include "config.h"
#include <stdbool.h>
#include "hitbox.h"
#include "local-cordinate.h"
#include <stdio.h>

typedef struct {
    unsigned int id;
    Local_Cordinate cord;
    Texture2D* texture;
    Hitbox hitbox;
    bool isActive;
    unsigned int ticks;
    float time; // seconds
} Sprite;

void sprite_create(Local_Cordinate_System* cordSys, Vector2 initPos, bool isActive, Texture2D* tex, Hitbox_e hb_type, Sprite* dest);

void sprite_translate(Sprite* target, Vector2 delta);

bool sprite_isRect(Sprite* target);
bool sprite_isPolar(Sprite* target);

#endif // !SPRITE_BASE_H_
