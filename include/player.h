#ifndef PLAYER_H_
#define PLAYER_H_

#include <config.h>
#include <raylib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <util.h>
#include "tama.h"

#define PLAYER_SPEED 5.0f
#define PLAYER_SPEED_SLOWMULTI 0.45f
#define PLAYER_TAMA_NUM 127
#define PLAYER_TAMA_SPEED 8.0f
#define PLAYER_TAMA_SHOT_SPEED 10 // per second (60 frames)

typedef struct Player {
    float x;
    float y;
    bool didHit;
    int score;
    int tick;
    Tama tama[PLAYER_TAMA_NUM];
} Player;

void player_control(Player* player);

void player_render(Player* player);

void player_update(Player* player);

void player_tama_update(Player* player);

void player_init(Player* player);

void player_shoot(Player* player);

#endif // PLAYER_H_
