#ifndef GAME_H_
#define GAME_H_

#include <raylib.h>
#include "player.h"
#include "boss.h"
#include "config.h"
#include "screens.h"
#include "local-cordinate.h"

typedef struct {
    Player player;
    BossSprite boss;
    Bosses selected_boss;
    Screens currentScr;
    Local_Cordinate_System GamePlaneRect;
    Local_Cordinate_System GamePlanePolar;
    int inited;
    int globalTick;
    float time;
} Game;

void game_init(Game* game);
void game_update(Game* game);
void game_draw(Game* game);

#endif  // GAME_H_
