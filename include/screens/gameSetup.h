#ifndef _GAMESETUP_H_
#define _GAMESETUP_H_

#include <raylib.h>
#include <screens.h>
#include <config.h>
#include <game.h>
#include <boss.h>

void game_setup_render(Game* game);

void game_setup_update(Game* game);

#endif // _GAMESETUP_H_