#ifndef GAMEEND_H_
#define GAMEEND_H_

#include <raylib.h>
#include <screens.h>
#include <config.h>
#include <util.h>
#include <player.h>
#include <string.h>

void gameend_render(Player* pl);

void gameend_update(Screens* scr, Player* pl);

#endif // GAMEEND_H_
