#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_

#include <raylib.h>
#include <config.h>
#include <screens.h>
#include <player.h>
#include <util.h>
#include <string.h>
#include <stdlib.h>

void gameplay_render(Player* pl);

void gameplay_update(Screens* scr);

#endif // GAMEPLAY_H_
