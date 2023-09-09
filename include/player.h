#ifndef PLAYER_H_
#define PLAYER_H_

#include <config.h>
#include <raylib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <util.h>

#define PLAYER_SPEED 6.0f
#define PLAYER_SPEED_SLOWMULTI 0.45f

typedef struct Player {
    float x;
    float y;
    bool didHit;
    int score;
} Player;

void player_control(Player* player);

void player_render(Player* player);

void player_init(Player* player);

#endif // PLAYER_H_
