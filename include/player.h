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

#define PLAYER_SPEED 512.0f
#define PLAYER_SPEED_SLOWMULTI 0.40f
#define PLAYER_TAMA_NUM 256
#define PLAYER_TAMA_SPEED 1536.0f
#define PLAYER_TAMA_SHOT_SPEED 100 // per second

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
