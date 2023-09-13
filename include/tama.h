#ifndef TAMA_H_
#define TAMA_H_

#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {
    SMALL,
    NORMAL,
    LARGE,
    OHUDA,
    STAR
} TamaType;

typedef struct {
    float cx;
    float cy;
    float r;
    float t;
    TamaType type;
    bool isFromPlayer;
    Texture2D texture;
    bool isActive;
} Tama;

void tama_render(Tama* tama);

void tama_setCenterPos(Tama* tama, float x, float y);
void tama_setPolPos(Tama* tama, float r, float t);

void tama_init(Tama *tama, float cx, float cy, TamaType type, Image img, bool isFromPlayer);

#endif // TAMA_H_