#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_

#include <raylib.h>
#include <config.h>
#include <screens.h>
#include <player.h>
#include <boss.h>
#include <game.h>
#include <util.h>
#include <stdio.h>

void gameplay_render(Game *game);

void gameplay_update(Game *game);

#endif // GAMEPLAY_H_
