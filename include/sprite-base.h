#ifndef SPRITE_BASE_H_
#define SPRITE_BASE_H_

#include <raylib.h>
#include "config.h"
#include <stdbool.h>
#include "hitbox.h"
#include <stdio.h>

typedef enum Position_Modes {
    RECT = 1,
    POLAR,
} Position_Modes;

typedef struct {
    unsigned int id;
    Position_Modes mode;
    Vector2 pos; // (x,y)(Rect), (r,t)(Polar)
    Vector2 aux_pos; // (NULL,NULL)(Rect), (center_x, center_y)(Polar)
    Texture2D* texture;
    Hitbox hitbox;
    bool isActive;
    unsigned int ticks;
    float time; // seconds
} Sprite;

Sprite sprite_create(Position_Modes mode, Vector2 pos, Vector2 aux_pos, bool isActive, Texture2D* tex, Hitbox_e hb_type);

void sprite_translate(Sprite* target, Vector2 delta);

bool sprite_isRect(Sprite* target);
bool sprite_isPolar(Sprite* target);

#endif // !SPRITE_BASE_H_
