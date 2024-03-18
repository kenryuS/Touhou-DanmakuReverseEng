#ifndef PLAYER_H_
#define PLAYER_H_

#include "config.h"
#include <raylib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "util.h"
#include "tama.h"
#include "sprite-base.h"

#define PLAYER_SPEED 7.0f
#define PLAYER_SPEED_SLOWMULTI 0.30f
#define PLAYER_TAMA_NUM 127
#define PLAYER_TAMA_SPEED 16.0f
#define PLAYER_TAMA_SHOT_SPEED 16 // per second (60 frames)

typedef struct {
    unsigned int score;
    unsigned short bome;
} Player_Status;

typedef struct {
    Sprite core;
    Player_Status status;
    Tama tama[PLAYER_TAMA_NUM];
} Player;

void player_control(Player* player);

void player_render(Player* player);

void player_update(Player* player);

void player_tama_update(Player* player);

Player player_init();

void player_shoot(Player* player);

#endif // PLAYER_H_
