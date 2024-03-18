#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_

#include <raylib.h>
#include <config.h>
#include <screens.h>
#include <player.h>
#include <boss.h>
#include <util.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void gameplay_render(Player* pl, BossSprite* boss, Bosses selected_boss);

void gameplay_update(Screens* scr, Player* pl, BossSprite* boss, Bosses selected_boss);

#endif // GAMEPLAY_H_
