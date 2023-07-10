#ifndef PLAYER_H_
#define PLAYER_H_

#include <config.h>
#include <raylib.h>

typedef struct Player {
    float x;
    float y;
    bool didHit;
    bool isActive;
} Player;

void player_control(Player* player);

void player_render(Player* player);

#endif // PLAYER_H_
