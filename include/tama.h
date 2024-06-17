#ifndef TAMA_H_
#define TAMA_H_

#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sprite-base.h"
#include "hitbox.h"

typedef enum {
    SMALL,
    NORMAL,
    LARGE,
    OHUDA,
    STAR,
    LASER
} TamaType;

typedef struct {
    Sprite core;
    TamaType type;
    bool isFromPlayer;
} Tama;

void tama_render(Tama* tama);

void tama_init(Tama *tama, Vector2 center_pos, TamaType type, Texture2D* texture, bool isFromPlayer, Hitbox_e hb_type);

#endif // TAMA_H_
