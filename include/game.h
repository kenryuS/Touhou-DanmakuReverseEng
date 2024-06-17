#ifndef GAME_H_
#define GAME_H_

#include "player.h"
#include "boss.h"
#include "screens.h"

typedef struct {
    Player player;
    BossSprite boss;
    Bosses selected_boss;
    Screens currentScr;
    int inited;
    int globalTick;
    float time;
} Game;

#endif  // GAME_H_