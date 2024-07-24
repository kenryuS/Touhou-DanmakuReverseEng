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
    float deltaTheta;
    float speed;
    float deltaSpeed;
} Tama;

typedef struct {
    float shotAngle;
    float shotSpeed;
    unsigned int interval;
    unsigned int time;
} tama_DirectionalShot;

typedef struct {
    float shotAngle;
    float deltaShotAngle;
    float shotSpeed;
    unsigned int interval;
    unsigned int time;
} tama_SpiralShot;

typedef struct {
    float shotAngle;
    float deltaShotAngle;
    float shotSpeed;
    unsigned char ShotCount;
    unsigned int interval;
    unsigned int time;
} tama_MultiSpiralShot;

// typedef struct {

// } tama_NWayShot;

void tama_render(Tama* tama);

void tama_init(Tama *tama, Vector2 center_pos, TamaType type, Texture2D* texture, bool isFromPlayer, Hitbox_e hb_type);

#endif // TAMA_H_
