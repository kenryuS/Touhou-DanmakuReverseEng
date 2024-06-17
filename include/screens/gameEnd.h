#ifndef GAMEEND_H_
#define GAMEEND_H_

#include <raylib.h>
#include <screens.h>
#include <config.h>
#include <util.h>
#include <player.h>
#include <game.h>

void gameend_render(Game *game);

void gameend_update(Game *game);

#endif // GAMEEND_H_
